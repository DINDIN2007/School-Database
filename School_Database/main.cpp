#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include <QWidget>
#include <QScrollArea>
#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QRadioButton>
#include <QComboBox>
#include <QHBoxLayout>

#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "School.h"

int main(int argc, char *argv[]) {
    // Starting the GUI application
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "ICS4U-School_Database_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    // Declaring the window
    MainWindow w;
    QWidget *contentWidget = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(contentWidget);
    contentWidget->setLayout(layout);

    // Declaring the elements in the GUI
    QScrollArea *scrollArea = w.findChild<QScrollArea *>("schoolDatabase");
    QTextEdit *firstNameBox = w.findChild<QTextEdit *>("firstName");
    QTextEdit *lastNameBox = w.findChild<QTextEdit *>("lastName");
    QTextEdit *addressBox = w.findChild<QTextEdit *>("address");
    QTextEdit *personIdBox = w.findChild<QTextEdit *>("id");

    QPushButton *addButton = w.findChild<QPushButton *>("Add");
    QPushButton *removeButton = w.findChild<QPushButton *>("Remove");
    QPushButton *cancelButton = w.findChild<QPushButton *>("Cancel");

    QRadioButton *studentButton = w.findChild<QRadioButton *>("isStudent");
    QRadioButton *teacherButton = w.findChild<QRadioButton *>("isTeacher");

    QLabel* teachableLabel = w.findChild<QLabel *>("grade_label");

    QLabel* lateLabel = w.findChild<QLabel *>("late_label");
    QPushButton* lateButton = w.findChild<QPushButton *>("late_button");
    QTextEdit* lateTextBox = w.findChild<QTextEdit *>("late_counter");

    QComboBox *gradeSelection = w.findChild<QComboBox *>("grade");
    gradeSelection->addItem("9");
    gradeSelection->addItem("10");
    gradeSelection->addItem("11");
    gradeSelection->addItem("12");
    gradeSelection->setCurrentIndex(-1);

    // Current Teachable Classes Available
    QStringList classes = {
        "English", "Math", "Biology", "History", "Physical Education", "Chemistry", "Physics", "Foreigh Language", "Health Education", "Computer Science"
    };

    QComboBox *teachableSelection = w.findChild<QComboBox *>("teachable");
    for (int i = 0; i < 10; i++) teachableSelection->addItem(classes[i]);
    teachableSelection->hide();
    teachableSelection->setCurrentIndex(-1);

    // Declaring the schoolDataBase
    School schoolDataBase;

    // Initialize item count
    int *itemCount = new int(0);  // Store count dynamically to modify in lambda
    Person *selectedPerson = nullptr;

    // Creating Random Students and Teachers
    QStringList randomFirstNames = {
        "John", "Jane", "Alex", "Chris", "Emily", "Katie", "Michael", "Sarah", "David", "Rachel",
        "James", "Olivia", "Mason", "Isabella", "Liam", "Sophia", "Benjamin", "Amelia", "Ethan", "Charlotte"
    };

    QStringList randomLastNames = {
        "Smith", "Johnson", "Brown", "Williams", "Jones", "Davis", "Miller", "Wilson", "Moore", "Taylor",
        "Anderson", "Thomas", "Jackson", "White", "Harris", "Martin", "Thompson", "Garcia", "Martinez", "Roberts"
    };

    QStringList randomAddresses = {
        "Main St", "Maple Ave", "Elm St", "Oak Dr", "Pine Rd",
        "Cedar Ln", "Birch Blvd", "Spruce Ct", "Chestnut Way", "Willow Pl",
        "Aspen Loop", "Sycamore Ter", "Poplar Cir", "Hickory Ln", "Redwood Trl",
        "Dogwood Ct", "Magnolia Blvd", "Sequoia Way", "Laurel St", "Juniper Rd"
    };

    // Adding 15 random students to the database
    for (int i = 0; i < 15; ++i) {
        QString firstName = randomFirstNames[i];
        QString lastName = randomLastNames[i];
        QString address = QString::number(rand() % 2000 + 1) + " " + randomAddresses[i];

        // Create a new student with random data
        std::string studentId = "S" + std::to_string(rand() % 89999 + 10000) + std::to_string(rand() % 8999 + 1000);
        Person *newStudent = new Student(firstName.toStdString(), lastName.toStdString(), address.toStdString(), rand() % 4 + 9, studentId);

        // Add the new student to the school database
        schoolDataBase.addPerson(newStudent);

        // Create a button for the student
        QPushButton *studentSelectButton = new QPushButton(firstName + " " + lastName);

        // Connect button click to show student details
        QObject::connect(studentSelectButton, &QPushButton::clicked, [=, &schoolDataBase, &selectedPerson]() mutable {
            selectedPerson = schoolDataBase.findPerson(studentSelectButton->text().toStdString());
            firstNameBox->setText(QString::fromStdString((selectedPerson->getFirstName())));
            lastNameBox->setText(QString::fromStdString((selectedPerson->getLastName())));
            addressBox->setText(QString::fromStdString((selectedPerson->getAddress())));
            personIdBox->setText(QString::fromStdString((selectedPerson->getId())));

            if (typeid(*selectedPerson) == typeid(Student)) {
                studentButton->setChecked(true);
                teacherButton->setChecked(false);
            }
            else {
                teacherButton->setChecked(true);
                studentButton->setChecked(false);
            }

            addButton->setText(QString("Edit"));
            removeButton->show();
            cancelButton->show();
        });

        studentSelectButton->setObjectName(firstName + " " + lastName); // Set object name for identification
        layout->addWidget(studentSelectButton); // Add the button to the layout
    }

    // Adding 5 random teachers to the database
    for (int i = 15; i < 20; ++i) {
        QString firstName = randomFirstNames[i];
        QString lastName = randomLastNames[i];
        QString address = QString::number(rand() % 2000 + 1) + " " + randomAddresses[i];

        // Create a new student with random data
        Person *newTeacher = new Teacher(firstName.toStdString(), lastName.toStdString(), address.toStdString(), classes[rand() % 10].toStdString(), ("C" + std::to_string(rand() % 8999 + 10000)));

        // Add the new student to the school database
        schoolDataBase.addPerson(newTeacher);

        // Create a button for the student
        QPushButton *teacherSelectButton = new QPushButton(firstName + " " + lastName);

        // Connect button click to show student details
        QObject::connect(teacherSelectButton, &QPushButton::clicked, [=, &schoolDataBase, &selectedPerson]() mutable {
            selectedPerson = schoolDataBase.findPerson(teacherSelectButton->text().toStdString());
            firstNameBox->setText(QString::fromStdString((selectedPerson->getFirstName())));
            lastNameBox->setText(QString::fromStdString((selectedPerson->getLastName())));
            addressBox->setText(QString::fromStdString((selectedPerson->getAddress())));
            personIdBox->setText(QString::fromStdString((selectedPerson->getId())));

            if (typeid(*selectedPerson) == typeid(Student)) {
                studentButton->setChecked(true);
                teacherButton->setChecked(false);
            }
            else {
                teacherButton->setChecked(true);
                studentButton->setChecked(false);
            }

            addButton->setText(QString("Edit"));
            removeButton->show();
            cancelButton->show();
        });

        teacherSelectButton->setObjectName(firstName + " " + lastName); // Set object name for identification
        layout->addWidget(teacherSelectButton); // Add the button to the layout
    }


    // Connect button click to add/edit a person's information
    QObject::connect(addButton, &QPushButton::clicked, [=, &schoolDataBase, &selectedPerson, &w]() mutable {
        (*itemCount)++;  // Increment item count
        QString firstName = firstNameBox->toPlainText();
        QString lastName = lastNameBox->toPlainText();
        QString address = addressBox->toPlainText();
        QString personId = personIdBox->toPlainText();

        // If no person is selected, this button basically adds a new person based on whats filled in the textboxs
        if (selectedPerson == nullptr) {
            if (!(firstName.isEmpty() || lastName.isEmpty())) {
                // Add it to the school database
                Person *newPerson;

                // Add a teacher
                if (teacherButton->isChecked()) {
                    std::string teachable = teachableSelection->currentText().toStdString();
                    newPerson = !address.isEmpty()
                                    ? new Teacher(firstName.toStdString(), lastName.toStdString(), address.toStdString(), teachable, personId.toStdString())
                                    : new Teacher(firstName.toStdString(), lastName.toStdString());

                    Teacher* t = dynamic_cast<Teacher *>(newPerson);
                    t->setTeachables(teachableSelection->currentText().toStdString());
                    teachableSelection->setCurrentIndex(-1);
                }

                // Add a student
                else {
                    int studentGrade = gradeSelection->currentText().toInt();
                    newPerson = !address.isEmpty()
                                    ? new Student(firstName.toStdString(), lastName.toStdString(), address.toStdString(), studentGrade, personId.toStdString())
                                    : new Student(firstName.toStdString(), lastName.toStdString());

                    Student* s = dynamic_cast<Student *>(newPerson);
                    s->setGrade(gradeSelection->currentIndex() + 9);
                    gradeSelection->setCurrentIndex(-1);
                }

                // Add that person to the database
                schoolDataBase.addPerson(newPerson);

                // Add a new button for that person in the UI database
                QString content = firstName + " " + lastName;
                QPushButton *infoButton = new QPushButton(content);

                // Clear the nameboxes for the next person
                firstNameBox->clear();
                lastNameBox->clear();
                addressBox->clear();
                personIdBox->clear();

                // Add the methods linked to that person's button
                QObject::connect(infoButton, &QPushButton::clicked, [=, &schoolDataBase, &selectedPerson]() mutable {
                    selectedPerson = schoolDataBase.findPerson(infoButton->text().toStdString());
                    firstNameBox->setText(QString::fromStdString((selectedPerson->getFirstName())));
                    lastNameBox->setText(QString::fromStdString((selectedPerson->getLastName())));
                    addressBox->setText(QString::fromStdString((selectedPerson->getAddress())));
                    personIdBox->setText(QString::fromStdString((selectedPerson->getId())));

                    if (typeid(*selectedPerson) == typeid(Student)) {
                        studentButton->setChecked(true);
                        teacherButton->setChecked(false);
                    }
                    else {
                        teacherButton->setChecked(true);
                        studentButton->setChecked(false);
                    }

                    addButton->setText(QString("Edit"));
                    removeButton->show();
                    cancelButton->show();
                });

                infoButton->setObjectName(content);
                layout->addWidget(infoButton);
            }
        }
        // Otherwise, if a person is selected, edit the information on a person
        else {
            // Find the person and retain the information displayed
            QPushButton *buttonToEdit = w.findChild<QPushButton*>(selectedPerson->getFirstName() + " " + selectedPerson->getLastName());
            selectedPerson->setFirstName(firstName.toStdString());
            selectedPerson->setLastName(lastName.toStdString());
            selectedPerson->setAddress(address.toStdString());

            // Custom UI if the person is a student
            if (typeid(*selectedPerson) == typeid(Student)) {
                Student* s = dynamic_cast<Student *>(selectedPerson);
                s->setGrade(gradeSelection->currentIndex() + 9);
                s->setStudentId(personId.toStdString());
                gradeSelection->setCurrentIndex(-1);
            }
            // or a teacher
            else {
                Teacher* t = dynamic_cast<Teacher *>(selectedPerson);
                t->setTeachables(teachableSelection->currentText().toStdString());
                t->setEmployeeId(personId.toStdString());
                teachableSelection->setCurrentIndex(-1);
            }

            // Clear the boxes
            firstNameBox->clear();
            lastNameBox->clear();
            addressBox->clear();
            personIdBox->clear();

            // Edit the button according to new information
            buttonToEdit->setText(QString::fromStdString(selectedPerson->getFirstName() + " " + selectedPerson->getLastName()));
            buttonToEdit->setObjectName(QString::fromStdString(selectedPerson->getFirstName() + " " + selectedPerson->getLastName()));

            // Set the selected person to null (no one is selected)
            selectedPerson = nullptr;
        }
    });

    // Connect methods to the remove person button
    QObject::connect(removeButton, &QPushButton::clicked, [=, &schoolDataBase, &selectedPerson, &w]() mutable {
        if (selectedPerson != nullptr) {
            // Find the person and his button
            QString name = QString::fromStdString(selectedPerson->getFirstName() + " " + selectedPerson->getLastName());
            QPushButton *buttonToRemove = w.findChild<QPushButton*>(name);

            // If the person exists, remove him from the school database and the UI database
            if (buttonToRemove) {
                layout->removeWidget(buttonToRemove);
                buttonToRemove->deleteLater();
                schoolDataBase.deletePerson(selectedPerson);
            }

            // Clear the textboxes and reset
            selectedPerson = nullptr;
            firstNameBox->clear();
            lastNameBox->clear();
            addressBox->clear();

            addButton->setText("Add Person");
            removeButton->hide();
            cancelButton->hide();
        }
    });
    removeButton->hide();

    // Connect methods to the cancel button (it just clears out the textboxes and resets the ui)
    QObject::connect(cancelButton, &QPushButton::clicked, [=]() mutable {
        firstNameBox->clear();
        lastNameBox->clear();
        addressBox->clear();
        personIdBox->clear();

        gradeSelection->setCurrentIndex(-1);
        teachableSelection->setCurrentIndex(-1);

        addButton->setText(QString("Add Person"));
        removeButton->hide();
        cancelButton->hide();
    });
    cancelButton->hide();

    // Connect methods to the teacher radioButton whenever its toggled
    QObject::connect(teacherButton, &QRadioButton::toggled, [=, &schoolDataBase, &selectedPerson](bool checked) mutable{
        // If it was checked by code (not manually), don't do anything
        if (!checked) return;

        // If it was the user who changed a student to a teacher, update that person's information
        if (selectedPerson != nullptr && typeid(*selectedPerson) == typeid(Student)) {
            std::string newId = "C" + selectedPerson->getId().substr(1, 5);
            Person* newTeacher = new Teacher(selectedPerson->getFirstName(), selectedPerson->getLastName(), selectedPerson->getAddress(), "English", newId);
            schoolDataBase.addPerson(newTeacher);
            schoolDataBase.deletePerson(selectedPerson);
            selectedPerson = newTeacher;
        }

        // Reset the UI
        teachableLabel->setText("Teachable");
        teachableSelection->show();
        gradeSelection->hide();

        lateButton->hide();
        lateLabel->hide();
        lateTextBox->hide();

        // Put the new information from that person
        if (selectedPerson != nullptr) {
            Teacher* currentTeacher = dynamic_cast<Teacher *>(selectedPerson);
            teachableSelection->setCurrentText(QString::fromStdString(currentTeacher->getTeachables()));
            personIdBox->setText(QString::fromStdString(currentTeacher->getId()));
        }
    });

    // Connect methods to the student radioButton whenever its toggled
    QObject::connect(studentButton, &QRadioButton::toggled, [=, &schoolDataBase, &selectedPerson](bool checked) mutable {
        // If it was checked by code (not manually), don't do anything
        if (!checked) return;

        // If it was the user who changed a student to a teacher, update that person's information
        if (selectedPerson != nullptr && typeid(*selectedPerson) == typeid(Teacher)) {
            std::string newId = "S" + selectedPerson->getId().substr(1) + "0000";
            Person* newStudent = new Student(selectedPerson->getFirstName(), selectedPerson->getLastName(), selectedPerson->getAddress(), 9, newId);
            schoolDataBase.addPerson(newStudent);
            schoolDataBase.deletePerson(selectedPerson);
            selectedPerson = newStudent;
        }

        // Reset the UI
        teachableLabel->setText("Grade");
        gradeSelection->show();
        teachableSelection->hide();

        lateButton->show();
        lateLabel->show();
        lateTextBox->show();

        // Put the new information from that person
        if (selectedPerson != nullptr) {
            Student* currentStudent = dynamic_cast<Student *>(selectedPerson);
            gradeSelection->setCurrentIndex(currentStudent->getGrade() - 9);
            personIdBox->setText(QString::fromStdString(currentStudent->getId()));
            lateTextBox->setText(QString::number(currentStudent->getNumLates()));
        }
    });

    // Whenever student radiobutton is toggled, the lateButton appears
    // This connects it to its method, which is simply to update the student's numOfLates
    QObject::connect(lateButton, &QPushButton::clicked, [=, &schoolDataBase, &selectedPerson]() mutable {
        Student* s = dynamic_cast<Student *>(selectedPerson);
        if (s) {
            s->addLate();
            lateTextBox->setText(QString::number(s->getNumLates()));
        }
    });

    // Show the GUI window
    contentWidget->setLayout(layout);
    scrollArea->setWidget(contentWidget);
    w.show();

    return a.exec();
}

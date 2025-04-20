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

    QComboBox *teachableSelection = w.findChild<QComboBox *>("teachable");
    QStringList classes = {
        "English", "Math", "Biology", "History", "Physical Education", "Chemistry", "Physics", "Foreigh Language", "Health Education", "Computer Science"
    };

    for (int i = 0; i < 10; i++) {
        teachableSelection->addItem(classes[i]);
    }

    teachableSelection->hide();

    // Declaring the schoolDataBase
    School schoolDataBase;

    // Initialize item count
    int *itemCount = new int(0);  // Store count dynamically to modify in lambda
    Person *selectedPerson = nullptr;

    QStringList firstNames = {
        "John", "Jane", "Alex", "Chris", "Emily", "Katie", "Michael", "Sarah", "David", "Rachel",
        "James", "Olivia", "Mason", "Isabella", "Liam", "Sophia", "Benjamin", "Amelia", "Ethan", "Charlotte"
    };

    QStringList lastNames = {
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
        QString firstName = firstNames[i];
        QString lastName = lastNames[i];
        QString address = QString::number(rand() % 2000 + 1) + " " + randomAddresses[i];

        // Create a new student with random data
        std::string studentId = "S" + std::to_string(rand() % 89999 + 10000) + std::to_string(rand() % 8999 + 1000);
        std::cout << studentId << std::endl;
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

                Student* s = dynamic_cast<Student *>(selectedPerson);
                lateTextBox->setText(QString::number(s->getNumLates()));
                gradeSelection->setCurrentIndex(dynamic_cast<Student *>(selectedPerson)->getGrade() - 9);
            }
            else {
                teacherButton->setChecked(true);
                studentButton->setChecked(false);
                teachableSelection->setCurrentText(QString::fromStdString(dynamic_cast<Teacher *>(selectedPerson)->getTeachables()));
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
        QString firstName = firstNames[i];
        QString lastName = lastNames[i];
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

                Student* s = dynamic_cast<Student *>(selectedPerson);
                lateTextBox->setText(QString::number(s->getNumLates()));
                gradeSelection->setCurrentIndex(dynamic_cast<Student *>(selectedPerson)->getGrade() - 9);
            }
            else {
                teacherButton->setChecked(true);
                studentButton->setChecked(false);
                teachableSelection->setCurrentText(QString::fromStdString(dynamic_cast<Teacher *>(selectedPerson)->getTeachables()));
            }

            addButton->setText(QString("Edit"));
            removeButton->show();
            cancelButton->show();
        });

        teacherSelectButton->setObjectName(firstName + " " + lastName); // Set object name for identification
        layout->addWidget(teacherSelectButton); // Add the button to the layout
    }


    // Connect button click to add a new label
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

                if (teacherButton->isChecked()) {
                    std::string teachable = teachableSelection->currentText().toStdString();
                    newPerson = !address.isEmpty()
                                    ? new Teacher(firstName.toStdString(), lastName.toStdString(), address.toStdString(), teachable, personId.toStdString())
                                    : new Teacher(firstName.toStdString(), lastName.toStdString());
                }
                else {
                    int studentGrade = gradeSelection->currentText().toInt();
                    newPerson = !address.isEmpty()
                                    ? new Student(firstName.toStdString(), lastName.toStdString(), address.toStdString(), studentGrade, personId.toStdString())
                                    : new Student(firstName.toStdString(), lastName.toStdString());
                }

                schoolDataBase.addPerson(newPerson);

                QString content = firstName + " " + lastName;
                QPushButton *infoButton = new QPushButton(content);

                firstNameBox->clear();
                lastNameBox->clear();
                addressBox->clear();

                QObject::connect(infoButton, &QPushButton::clicked, [=, &schoolDataBase, &selectedPerson]() mutable {
                    selectedPerson = schoolDataBase.findPerson(infoButton->text().toStdString());
                    firstNameBox->setText(QString::fromStdString((selectedPerson->getFirstName())));
                    lastNameBox->setText(QString::fromStdString((selectedPerson->getLastName())));
                    addressBox->setText(QString::fromStdString((selectedPerson->getAddress())));
                    personIdBox->setText(QString::fromStdString((selectedPerson->getId())));

                    if (typeid(*selectedPerson) == typeid(Student)) {
                        studentButton->setChecked(true);
                        teacherButton->setChecked(false);

                        Student* s = dynamic_cast<Student *>(selectedPerson);
                        lateTextBox->setText(QString::number(s->getNumLates()));
                        gradeSelection->setCurrentIndex(dynamic_cast<Student *>(selectedPerson)->getGrade() - 9);
                    }
                    else {
                        teacherButton->setChecked(true);
                        studentButton->setChecked(false);
                        teachableSelection->setCurrentText(QString::fromStdString(dynamic_cast<Teacher *>(selectedPerson)->getTeachables()));
                    }

                    addButton->setText(QString("Edit"));
                    removeButton->show();
                    cancelButton->show();
                });

                infoButton->setObjectName(content);
                layout->addWidget(infoButton);
            }
        }
        // Otherwise, edit the information on a person
        else {
            QPushButton *buttonToEdit = w.findChild<QPushButton*>(selectedPerson->getFirstName() + " " + selectedPerson->getLastName());
            selectedPerson->setFirstName(firstName.toStdString());
            selectedPerson->setLastName(lastName.toStdString());
            selectedPerson->setAddress(address.toStdString());

            if (typeid(*selectedPerson) == typeid(Student)) {
                Student* s = dynamic_cast<Student *>(selectedPerson);
                s->setGrade(gradeSelection->currentIndex() + 9);
                s->setStudentId(personId.toStdString());
                gradeSelection->setCurrentIndex(-1);
            }
            else {
                Teacher* t = dynamic_cast<Teacher *>(selectedPerson);
                t->setTeachables(teachableSelection->currentText().toStdString());
                t->setEmployeeId(personId.toStdString());
                teachableSelection->setCurrentIndex(-1);
            }

            firstNameBox->clear();
            lastNameBox->clear();
            addressBox->clear();
            personIdBox->clear();

            buttonToEdit->setText(QString::fromStdString(selectedPerson->getFirstName() + " " + selectedPerson->getLastName()));
            buttonToEdit->setObjectName(QString::fromStdString(selectedPerson->getFirstName() + " " + selectedPerson->getLastName()));

            selectedPerson = nullptr;
        }
    });

    QObject::connect(removeButton, &QPushButton::clicked, [=, &schoolDataBase, &selectedPerson, &w]() mutable {
        if (selectedPerson != nullptr) {
            QString name = QString::fromStdString(selectedPerson->getFirstName() + " " + selectedPerson->getLastName());

            QPushButton *buttonToRemove = w.findChild<QPushButton*>(name);

            if (buttonToRemove) {
                layout->removeWidget(buttonToRemove);
                buttonToRemove->deleteLater();
                schoolDataBase.deletePerson(selectedPerson);
            }

            selectedPerson = nullptr;

            firstNameBox->clear();
            lastNameBox->clear();
            addressBox->clear();

            addButton->setText("Add Person");
            removeButton->hide();
            cancelButton->hide();
        }
    });

    QObject::connect(cancelButton, &QPushButton::clicked, [=]() mutable {
        firstNameBox->clear();
        lastNameBox->clear();
        addressBox->clear();

        addButton->setText(QString("Add Person"));
        removeButton->hide();
        cancelButton->hide();
    });

    cancelButton->hide();
    removeButton->hide();

    QObject::connect(teacherButton, &QRadioButton::toggled, [=]() mutable{
        if (selectedPerson == nullptr || typeid(*selectedPerson) == typeid(Teacher)) {
            teachableLabel->setText("Teachable");
            teachableSelection->show();
            gradeSelection->hide();

            lateButton->hide();
            lateLabel->hide();
            lateTextBox->hide();
        }
        else {
            Person* newTeacher = new Teacher(selectedPerson->getFirstName(), selectedPerson->getLastName(), selectedPerson->getAddress(), "English", "C" + selectedPerson->getId().substr(1));
            schoolDataBase.addPerson(newTeacher);
            schoolDataBase.deletePerson(selectedPerson);
        }
    });

    QObject::connect(studentButton, &QRadioButton::toggled, [=]() mutable {
        if (selectedPerson == nullptr || typeid(*selectedPerson) == typeid(Student)) {
            teachableLabel->setText("Grade");
            gradeSelection->show();
            teachableSelection->hide();

            lateButton->show();
            lateLabel->show();
            lateTextBox->show();
        }
        else {
            Person* newStudent = new Student(selectedPerson->getFirstName(), selectedPerson->getLastName(), selectedPerson->getAddress(), 9, "S" + selectedPerson->getId().substr(1));
            schoolDataBase.addPerson(newStudent);
            schoolDataBase.deletePerson(selectedPerson);
        }
    });

    QObject::connect(lateButton, &QPushButton::clicked, [=]() mutable {
        Student* s = dynamic_cast<Student *>(selectedPerson);

        std::cout << ((selectedPerson == nullptr) ? "null" : "not null") << std::endl;

        if (s) {
            s->addLate();
            lateTextBox->setText(QString::number(s->getNumLates()));
        }

        // std::cout << "Actual type: " << typeid(*selectedPerson).name() << std::endl;
    });

    // Show the GUI window
    contentWidget->setLayout(layout);
    scrollArea->setWidget(contentWidget);
    w.show();

    return a.exec();
}

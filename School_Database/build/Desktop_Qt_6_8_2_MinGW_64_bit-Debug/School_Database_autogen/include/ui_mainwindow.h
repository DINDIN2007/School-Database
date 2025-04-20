/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QScrollArea *schoolDatabase;
    QWidget *scrollAreaWidgetContents;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *toolbox;
    QLabel *label;
    QTextEdit *firstName;
    QLabel *label_2;
    QTextEdit *lastName;
    QLabel *label_3;
    QTextEdit *address;
    QLabel *grade_label;
    QComboBox *grade;
    QComboBox *teachable;
    QLabel *i;
    QTextEdit *id;
    QHBoxLayout *late_layout;
    QLabel *late_label;
    QTextEdit *late_counter;
    QPushButton *late_button;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *isTeacher;
    QRadioButton *isStudent;
    QHBoxLayout *horizontalLayout;
    QPushButton *Add;
    QPushButton *Remove;
    QPushButton *Cancel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(943, 602);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        schoolDatabase = new QScrollArea(centralwidget);
        schoolDatabase->setObjectName("schoolDatabase");
        schoolDatabase->setGeometry(QRect(30, 20, 381, 521));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(schoolDatabase->sizePolicy().hasHeightForWidth());
        schoolDatabase->setSizePolicy(sizePolicy);
        schoolDatabase->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        schoolDatabase->setWidgetResizable(true);
        schoolDatabase->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 379, 16));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy1);
        schoolDatabase->setWidget(scrollAreaWidgetContents);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(430, 20, 321, 521));
        toolbox = new QVBoxLayout(verticalLayoutWidget);
        toolbox->setObjectName("toolbox");
        toolbox->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        toolbox->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 30));

        toolbox->addWidget(label);

        firstName = new QTextEdit(verticalLayoutWidget);
        firstName->setObjectName("firstName");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(firstName->sizePolicy().hasHeightForWidth());
        firstName->setSizePolicy(sizePolicy2);
        firstName->setMaximumSize(QSize(16777215, 40));

        toolbox->addWidget(firstName);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(16777215, 30));

        toolbox->addWidget(label_2);

        lastName = new QTextEdit(verticalLayoutWidget);
        lastName->setObjectName("lastName");
        lastName->setMaximumSize(QSize(16777215, 40));

        toolbox->addWidget(lastName);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(16777215, 30));

        toolbox->addWidget(label_3);

        address = new QTextEdit(verticalLayoutWidget);
        address->setObjectName("address");
        address->setMaximumSize(QSize(16777215, 40));

        toolbox->addWidget(address);

        grade_label = new QLabel(verticalLayoutWidget);
        grade_label->setObjectName("grade_label");
        sizePolicy1.setHeightForWidth(grade_label->sizePolicy().hasHeightForWidth());
        grade_label->setSizePolicy(sizePolicy1);
        grade_label->setMaximumSize(QSize(16777215, 30));

        toolbox->addWidget(grade_label);

        grade = new QComboBox(verticalLayoutWidget);
        grade->setObjectName("grade");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(grade->sizePolicy().hasHeightForWidth());
        grade->setSizePolicy(sizePolicy3);
        grade->setMinimumSize(QSize(0, 10));
        grade->setMaximumSize(QSize(16777215, 40));

        toolbox->addWidget(grade);

        teachable = new QComboBox(verticalLayoutWidget);
        teachable->setObjectName("teachable");
        sizePolicy3.setHeightForWidth(teachable->sizePolicy().hasHeightForWidth());
        teachable->setSizePolicy(sizePolicy3);
        teachable->setMinimumSize(QSize(0, 10));
        teachable->setMaximumSize(QSize(16777215, 40));

        toolbox->addWidget(teachable);

        i = new QLabel(verticalLayoutWidget);
        i->setObjectName("i");
        i->setMaximumSize(QSize(16777215, 30));

        toolbox->addWidget(i);

        id = new QTextEdit(verticalLayoutWidget);
        id->setObjectName("id");
        id->setMaximumSize(QSize(16777215, 40));

        toolbox->addWidget(id);

        late_layout = new QHBoxLayout();
        late_layout->setSpacing(0);
        late_layout->setObjectName("late_layout");
        late_layout->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
        late_label = new QLabel(verticalLayoutWidget);
        late_label->setObjectName("late_label");
        late_label->setMaximumSize(QSize(300, 10));

        late_layout->addWidget(late_label);

        late_counter = new QTextEdit(verticalLayoutWidget);
        late_counter->setObjectName("late_counter");
        late_counter->setEnabled(false);
        late_counter->setMaximumSize(QSize(40, 30));
        late_counter->setReadOnly(true);

        late_layout->addWidget(late_counter);

        late_button = new QPushButton(verticalLayoutWidget);
        late_button->setObjectName("late_button");
        late_button->setMaximumSize(QSize(30, 30));

        late_layout->addWidget(late_button);


        toolbox->addLayout(late_layout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        isTeacher = new QRadioButton(verticalLayoutWidget);
        isTeacher->setObjectName("isTeacher");

        horizontalLayout_2->addWidget(isTeacher);

        isStudent = new QRadioButton(verticalLayoutWidget);
        isStudent->setObjectName("isStudent");
        isStudent->setChecked(true);

        horizontalLayout_2->addWidget(isStudent);


        toolbox->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(7);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
        Add = new QPushButton(verticalLayoutWidget);
        Add->setObjectName("Add");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(Add->sizePolicy().hasHeightForWidth());
        Add->setSizePolicy(sizePolicy4);
        Add->setMaximumSize(QSize(16777215, 40));
        Add->setCursor(QCursor(Qt::CursorShape::OpenHandCursor));

        horizontalLayout->addWidget(Add);

        Remove = new QPushButton(verticalLayoutWidget);
        Remove->setObjectName("Remove");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(Remove->sizePolicy().hasHeightForWidth());
        Remove->setSizePolicy(sizePolicy5);
        Remove->setMaximumSize(QSize(16777215, 40));

        horizontalLayout->addWidget(Remove);


        toolbox->addLayout(horizontalLayout);

        Cancel = new QPushButton(verticalLayoutWidget);
        Cancel->setObjectName("Cancel");

        toolbox->addWidget(Cancel);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 943, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "First Name", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Last Name", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Address", nullptr));
        grade_label->setText(QCoreApplication::translate("MainWindow", "Grade", nullptr));
        i->setText(QCoreApplication::translate("MainWindow", "Student ID", nullptr));
        late_label->setText(QCoreApplication::translate("MainWindow", "Late", nullptr));
        late_button->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        isTeacher->setText(QCoreApplication::translate("MainWindow", "Teacher", nullptr));
        isStudent->setText(QCoreApplication::translate("MainWindow", "Student", nullptr));
        Add->setText(QCoreApplication::translate("MainWindow", "Add Person", nullptr));
        Remove->setText(QCoreApplication::translate("MainWindow", "Remove Person", nullptr));
        Cancel->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

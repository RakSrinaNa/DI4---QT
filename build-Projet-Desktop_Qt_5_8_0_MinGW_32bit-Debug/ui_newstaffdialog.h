/********************************************************************************
** Form generated from reading UI file 'newstaffdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWSTAFFDIALOG_H
#define UI_NEWSTAFFDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewStaffDialog
{
public:
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *firstNameLabel;
    QLineEdit *firstNameLineEdit;
    QLabel *lastNameLabel;
    QLineEdit *lastNameLineEdit;
    QLabel *typeLabel;
    QComboBox *typeComboBox;
    QLabel *loginLabel;
    QLineEdit *loginLineEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordLineEdit;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *NewStaffDialog)
    {
        if (NewStaffDialog->objectName().isEmpty())
            NewStaffDialog->setObjectName(QStringLiteral("NewStaffDialog"));
        NewStaffDialog->resize(400, 171);
        formLayoutWidget_2 = new QWidget(NewStaffDialog);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(9, 9, 381, 155));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        firstNameLabel = new QLabel(formLayoutWidget_2);
        firstNameLabel->setObjectName(QStringLiteral("firstNameLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, firstNameLabel);

        firstNameLineEdit = new QLineEdit(formLayoutWidget_2);
        firstNameLineEdit->setObjectName(QStringLiteral("firstNameLineEdit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, firstNameLineEdit);

        lastNameLabel = new QLabel(formLayoutWidget_2);
        lastNameLabel->setObjectName(QStringLiteral("lastNameLabel"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, lastNameLabel);

        lastNameLineEdit = new QLineEdit(formLayoutWidget_2);
        lastNameLineEdit->setObjectName(QStringLiteral("lastNameLineEdit"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, lastNameLineEdit);

        typeLabel = new QLabel(formLayoutWidget_2);
        typeLabel->setObjectName(QStringLiteral("typeLabel"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, typeLabel);

        typeComboBox = new QComboBox(formLayoutWidget_2);
        typeComboBox->setObjectName(QStringLiteral("typeComboBox"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, typeComboBox);

        loginLabel = new QLabel(formLayoutWidget_2);
        loginLabel->setObjectName(QStringLiteral("loginLabel"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, loginLabel);

        loginLineEdit = new QLineEdit(formLayoutWidget_2);
        loginLineEdit->setObjectName(QStringLiteral("loginLineEdit"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, loginLineEdit);

        passwordLabel = new QLabel(formLayoutWidget_2);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, passwordLabel);

        passwordLineEdit = new QLineEdit(formLayoutWidget_2);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, passwordLineEdit);

        okButton = new QPushButton(formLayoutWidget_2);
        okButton->setObjectName(QStringLiteral("okButton"));

        formLayout_2->setWidget(5, QFormLayout::FieldRole, okButton);

        cancelButton = new QPushButton(formLayoutWidget_2);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, cancelButton);


        retranslateUi(NewStaffDialog);

        QMetaObject::connectSlotsByName(NewStaffDialog);
    } // setupUi

    void retranslateUi(QDialog *NewStaffDialog)
    {
        NewStaffDialog->setWindowTitle(QApplication::translate("NewStaffDialog", "Dialog", Q_NULLPTR));
        firstNameLabel->setText(QApplication::translate("NewStaffDialog", "First name :", Q_NULLPTR));
        lastNameLabel->setText(QApplication::translate("NewStaffDialog", "Last name :", Q_NULLPTR));
        typeLabel->setText(QApplication::translate("NewStaffDialog", "Type :", Q_NULLPTR));
        loginLabel->setText(QApplication::translate("NewStaffDialog", "Login :", Q_NULLPTR));
        passwordLabel->setText(QApplication::translate("NewStaffDialog", "Password :", Q_NULLPTR));
        okButton->setText(QApplication::translate("NewStaffDialog", "OK", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("NewStaffDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NewStaffDialog: public Ui_NewStaffDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWSTAFFDIALOG_H

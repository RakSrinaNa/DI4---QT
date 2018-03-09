/********************************************************************************
** Form generated from reading UI file 'newpatientdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPATIENTDIALOG_H
#define UI_NEWPATIENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewPatientDialog
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *lastNameLabel;
    QLineEdit *lastNameLineEdit;
    QLabel *firstNameLabel;
    QLineEdit *firstNameLineEdit;
    QLabel *addressLabel;
    QLineEdit *addressLineEdit;
    QLabel *cityLabel;
    QLineEdit *cityLineEdit;
    QLabel *postalCodeLabel;
    QLineEdit *postalCodeLineEdit;
    QLabel *dayOfConsultationLabel;
    QDateEdit *dayOfConsultationDateEdit;
    QLabel *durationLabel;
    QTimeEdit *durationTimeEdit;
    QLabel *priorityLabel;
    QComboBox *priorityComboBox;
    QLabel *ressourcesLabel;
    QListWidget *resourcesListWidget;
    QLabel *commentLabel;
    QLineEdit *commentLineEdit;
    QLabel *phoneLabel;
    QLineEdit *phoneLineEdit;
    QPushButton *cancelButton;
    QPushButton *okButton;

    void setupUi(QDialog *NewPatientDialog)
    {
        if (NewPatientDialog->objectName().isEmpty())
            NewPatientDialog->setObjectName(QStringLiteral("NewPatientDialog"));
        NewPatientDialog->resize(400, 381);
        formLayoutWidget = new QWidget(NewPatientDialog);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(9, 9, 381, 364));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        lastNameLabel = new QLabel(formLayoutWidget);
        lastNameLabel->setObjectName(QStringLiteral("lastNameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lastNameLabel);

        lastNameLineEdit = new QLineEdit(formLayoutWidget);
        lastNameLineEdit->setObjectName(QStringLiteral("lastNameLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lastNameLineEdit);

        firstNameLabel = new QLabel(formLayoutWidget);
        firstNameLabel->setObjectName(QStringLiteral("firstNameLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, firstNameLabel);

        firstNameLineEdit = new QLineEdit(formLayoutWidget);
        firstNameLineEdit->setObjectName(QStringLiteral("firstNameLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, firstNameLineEdit);

        addressLabel = new QLabel(formLayoutWidget);
        addressLabel->setObjectName(QStringLiteral("addressLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, addressLabel);

        addressLineEdit = new QLineEdit(formLayoutWidget);
        addressLineEdit->setObjectName(QStringLiteral("addressLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, addressLineEdit);

        cityLabel = new QLabel(formLayoutWidget);
        cityLabel->setObjectName(QStringLiteral("cityLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, cityLabel);

        cityLineEdit = new QLineEdit(formLayoutWidget);
        cityLineEdit->setObjectName(QStringLiteral("cityLineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, cityLineEdit);

        postalCodeLabel = new QLabel(formLayoutWidget);
        postalCodeLabel->setObjectName(QStringLiteral("postalCodeLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, postalCodeLabel);

        postalCodeLineEdit = new QLineEdit(formLayoutWidget);
        postalCodeLineEdit->setObjectName(QStringLiteral("postalCodeLineEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, postalCodeLineEdit);

        dayOfConsultationLabel = new QLabel(formLayoutWidget);
        dayOfConsultationLabel->setObjectName(QStringLiteral("dayOfConsultationLabel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, dayOfConsultationLabel);

        dayOfConsultationDateEdit = new QDateEdit(formLayoutWidget);
        dayOfConsultationDateEdit->setObjectName(QStringLiteral("dayOfConsultationDateEdit"));
        dayOfConsultationDateEdit->setCalendarPopup(true);

        formLayout->setWidget(5, QFormLayout::FieldRole, dayOfConsultationDateEdit);

        durationLabel = new QLabel(formLayoutWidget);
        durationLabel->setObjectName(QStringLiteral("durationLabel"));

        formLayout->setWidget(6, QFormLayout::LabelRole, durationLabel);

        durationTimeEdit = new QTimeEdit(formLayoutWidget);
        durationTimeEdit->setObjectName(QStringLiteral("durationTimeEdit"));
        durationTimeEdit->setCalendarPopup(false);
        durationTimeEdit->setTime(QTime(1, 0, 0));

        formLayout->setWidget(6, QFormLayout::FieldRole, durationTimeEdit);

        priorityLabel = new QLabel(formLayoutWidget);
        priorityLabel->setObjectName(QStringLiteral("priorityLabel"));

        formLayout->setWidget(7, QFormLayout::LabelRole, priorityLabel);

        priorityComboBox = new QComboBox(formLayoutWidget);
        priorityComboBox->setObjectName(QStringLiteral("priorityComboBox"));

        formLayout->setWidget(7, QFormLayout::FieldRole, priorityComboBox);

        ressourcesLabel = new QLabel(formLayoutWidget);
        ressourcesLabel->setObjectName(QStringLiteral("ressourcesLabel"));

        formLayout->setWidget(8, QFormLayout::LabelRole, ressourcesLabel);

        resourcesListWidget = new QListWidget(formLayoutWidget);
        resourcesListWidget->setObjectName(QStringLiteral("resourcesListWidget"));
        resourcesListWidget->setMaximumSize(QSize(16777215, 73));
        resourcesListWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
        resourcesListWidget->setProperty("isWrapping", QVariant(false));
        resourcesListWidget->setResizeMode(QListView::Fixed);

        formLayout->setWidget(8, QFormLayout::FieldRole, resourcesListWidget);

        commentLabel = new QLabel(formLayoutWidget);
        commentLabel->setObjectName(QStringLiteral("commentLabel"));

        formLayout->setWidget(9, QFormLayout::LabelRole, commentLabel);

        commentLineEdit = new QLineEdit(formLayoutWidget);
        commentLineEdit->setObjectName(QStringLiteral("commentLineEdit"));

        formLayout->setWidget(9, QFormLayout::FieldRole, commentLineEdit);

        phoneLabel = new QLabel(formLayoutWidget);
        phoneLabel->setObjectName(QStringLiteral("phoneLabel"));

        formLayout->setWidget(10, QFormLayout::LabelRole, phoneLabel);

        phoneLineEdit = new QLineEdit(formLayoutWidget);
        phoneLineEdit->setObjectName(QStringLiteral("phoneLineEdit"));

        formLayout->setWidget(10, QFormLayout::FieldRole, phoneLineEdit);

        cancelButton = new QPushButton(formLayoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        formLayout->setWidget(11, QFormLayout::LabelRole, cancelButton);

        okButton = new QPushButton(formLayoutWidget);
        okButton->setObjectName(QStringLiteral("okButton"));

        formLayout->setWidget(11, QFormLayout::FieldRole, okButton);


        retranslateUi(NewPatientDialog);

        cancelButton->setDefault(false);
        okButton->setDefault(true);


        QMetaObject::connectSlotsByName(NewPatientDialog);
    } // setupUi

    void retranslateUi(QDialog *NewPatientDialog)
    {
        NewPatientDialog->setWindowTitle(QApplication::translate("NewPatientDialog", "Dialog", Q_NULLPTR));
        lastNameLabel->setText(QApplication::translate("NewPatientDialog", "Last name :", Q_NULLPTR));
        firstNameLabel->setText(QApplication::translate("NewPatientDialog", "First name :", Q_NULLPTR));
        addressLabel->setText(QApplication::translate("NewPatientDialog", "Address :", Q_NULLPTR));
        cityLabel->setText(QApplication::translate("NewPatientDialog", "City :", Q_NULLPTR));
        postalCodeLabel->setText(QApplication::translate("NewPatientDialog", "Postal code :", Q_NULLPTR));
        dayOfConsultationLabel->setText(QApplication::translate("NewPatientDialog", "Day of consultation :", Q_NULLPTR));
        durationLabel->setText(QApplication::translate("NewPatientDialog", "Duration :", Q_NULLPTR));
        priorityLabel->setText(QApplication::translate("NewPatientDialog", "Priority :", Q_NULLPTR));
        ressourcesLabel->setText(QApplication::translate("NewPatientDialog", "Ressources :", Q_NULLPTR));
        commentLabel->setText(QApplication::translate("NewPatientDialog", "Comment :", Q_NULLPTR));
        phoneLabel->setText(QApplication::translate("NewPatientDialog", "Phone :", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("NewPatientDialog", "Cancel", Q_NULLPTR));
        okButton->setText(QApplication::translate("NewPatientDialog", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NewPatientDialog: public Ui_NewPatientDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPATIENTDIALOG_H

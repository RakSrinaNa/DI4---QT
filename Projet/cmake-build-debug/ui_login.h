/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *loginEdit;
    QLabel *label_2;
    QLineEdit *passwordEdit;
    QPushButton *cancelButton;
    QPushButton *okButton;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(235, 100);
        Login->setMinimumSize(QSize(235, 100));
        Login->setMaximumSize(QSize(235, 100));
        Login->setCursor(QCursor(Qt::CrossCursor));
        formLayoutWidget = new QWidget(Login);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 10, 216, 86));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        loginEdit = new QLineEdit(formLayoutWidget);
        loginEdit->setObjectName(QStringLiteral("loginEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, loginEdit);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        passwordEdit = new QLineEdit(formLayoutWidget);
        passwordEdit->setObjectName(QStringLiteral("passwordEdit"));
        passwordEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, passwordEdit);

        cancelButton = new QPushButton(formLayoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        formLayout->setWidget(2, QFormLayout::LabelRole, cancelButton);

        okButton = new QPushButton(formLayoutWidget);
        okButton->setObjectName(QStringLiteral("okButton"));

        formLayout->setWidget(2, QFormLayout::FieldRole, okButton);


        retranslateUi(Login);
        QObject::connect(cancelButton, SIGNAL(clicked()), Login, SLOT(reject()));

        okButton->setDefault(true);


        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Login", 0));
        label->setText(QApplication::translate("Login", "Login", 0));
        loginEdit->setText(QApplication::translate("Login", "Admin", 0));
        label_2->setText(QApplication::translate("Login", "Password", 0));
        passwordEdit->setText(QApplication::translate("Login", "Password", 0));
        cancelButton->setText(QApplication::translate("Login", "Cancel", 0));
        okButton->setText(QApplication::translate("Login", "Connect", 0));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H

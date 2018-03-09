/********************************************************************************
** Form generated from reading UI file 'aproposdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APROPOSDIALOG_H
#define UI_APROPOSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AProposDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *Version;
    QLabel *label_2;

    void setupUi(QDialog *AProposDialog)
    {
        if (AProposDialog->objectName().isEmpty())
            AProposDialog->setObjectName(QStringLiteral("AProposDialog"));
        AProposDialog->resize(300, 169);
        verticalLayoutWidget = new QWidget(AProposDialog);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 302, 160));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/Ressources/PolyLogo.png")));

        verticalLayout->addWidget(label);

        Version = new QLabel(verticalLayoutWidget);
        Version->setObjectName(QStringLiteral("Version"));
        Version->setAutoFillBackground(false);
        Version->setMidLineWidth(1);
        Version->setTextFormat(Qt::AutoText);
        Version->setScaledContents(false);
        Version->setIndent(-1);

        verticalLayout->addWidget(Version, 0, Qt::AlignHCenter);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2, 0, Qt::AlignHCenter);


        retranslateUi(AProposDialog);

        QMetaObject::connectSlotsByName(AProposDialog);
    } // setupUi

    void retranslateUi(QDialog *AProposDialog)
    {
        AProposDialog->setWindowTitle(QApplication::translate("AProposDialog", "Dialog", Q_NULLPTR));
        label->setText(QString());
        Version->setText(QApplication::translate("AProposDialog", "Version 1.0", Q_NULLPTR));
        label_2->setText(QApplication::translate("AProposDialog", "Couchoud Thomas & Coleau Victor", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AProposDialog: public Ui_AProposDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APROPOSDIALOG_H

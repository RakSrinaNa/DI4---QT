/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuitter;
    QAction *actionPatient;
    QAction *actionPersonnel_de_soin;
    QAction *actionA_propos;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_2;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *firstNameEdit;
    QLineEdit *lastNameEdit;
    QTableView *tableView;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_4;
    QWidget *verticalWidget_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QDateEdit *planDateEdit;
    QPushButton *planPushButton;
    QTextBrowser *planTextBrowser;
    QGridLayout *gridLayout;
    QPushButton *savePushButton;
    QPushButton *pathPushButton;
    QLineEdit *pathLineEdit;
    QLineEdit *saveLineEdit;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuAjouter;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(686, 544);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        actionPatient = new QAction(MainWindow);
        actionPatient->setObjectName(QStringLiteral("actionPatient"));
        actionPersonnel_de_soin = new QAction(MainWindow);
        actionPersonnel_de_soin->setObjectName(QStringLiteral("actionPersonnel_de_soin"));
        actionA_propos = new QAction(MainWindow);
        actionA_propos->setObjectName(QStringLiteral("actionA_propos"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMinimumSize(QSize(206, 251));
        tabWidget->setAutoFillBackground(true);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy1);
        tab->setMinimumSize(QSize(535, 225));
        tab->setLayoutDirection(Qt::LeftToRight);
        tab->setAutoFillBackground(true);
        tab->setStyleSheet(QStringLiteral(""));
        horizontalLayout_2 = new QHBoxLayout(tab);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalWidget = new QWidget(tab);
        verticalWidget->setObjectName(QStringLiteral("verticalWidget"));
        sizePolicy.setHeightForWidth(verticalWidget->sizePolicy().hasHeightForWidth());
        verticalWidget->setSizePolicy(sizePolicy);
        verticalWidget->setMinimumSize(QSize(0, 0));
        verticalWidget->setAutoFillBackground(true);
        verticalWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(verticalWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        firstNameEdit = new QLineEdit(verticalWidget);
        firstNameEdit->setObjectName(QStringLiteral("firstNameEdit"));

        horizontalLayout->addWidget(firstNameEdit);

        lastNameEdit = new QLineEdit(verticalWidget);
        lastNameEdit->setObjectName(QStringLiteral("lastNameEdit"));

        horizontalLayout->addWidget(lastNameEdit);


        verticalLayout_2->addLayout(horizontalLayout);

        tableView = new QTableView(verticalWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        sizePolicy.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_2->addWidget(tableView);


        horizontalLayout_2->addWidget(verticalWidget);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_4 = new QVBoxLayout(tab_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalWidget_2 = new QWidget(tab_2);
        verticalWidget_2->setObjectName(QStringLiteral("verticalWidget_2"));
        verticalLayout_3 = new QVBoxLayout(verticalWidget_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        planDateEdit = new QDateEdit(verticalWidget_2);
        planDateEdit->setObjectName(QStringLiteral("planDateEdit"));

        horizontalLayout_4->addWidget(planDateEdit);

        planPushButton = new QPushButton(verticalWidget_2);
        planPushButton->setObjectName(QStringLiteral("planPushButton"));

        horizontalLayout_4->addWidget(planPushButton);


        verticalLayout_3->addLayout(horizontalLayout_4);

        planTextBrowser = new QTextBrowser(verticalWidget_2);
        planTextBrowser->setObjectName(QStringLiteral("planTextBrowser"));
        sizePolicy.setHeightForWidth(planTextBrowser->sizePolicy().hasHeightForWidth());
        planTextBrowser->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(planTextBrowser);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        savePushButton = new QPushButton(verticalWidget_2);
        savePushButton->setObjectName(QStringLiteral("savePushButton"));

        gridLayout->addWidget(savePushButton, 1, 1, 1, 1);

        pathPushButton = new QPushButton(verticalWidget_2);
        pathPushButton->setObjectName(QStringLiteral("pathPushButton"));

        gridLayout->addWidget(pathPushButton, 0, 1, 1, 1);

        pathLineEdit = new QLineEdit(verticalWidget_2);
        pathLineEdit->setObjectName(QStringLiteral("pathLineEdit"));
        pathLineEdit->setReadOnly(true);

        gridLayout->addWidget(pathLineEdit, 0, 0, 1, 1);

        saveLineEdit = new QLineEdit(verticalWidget_2);
        saveLineEdit->setObjectName(QStringLiteral("saveLineEdit"));

        gridLayout->addWidget(saveLineEdit, 1, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout);


        verticalLayout_4->addWidget(verticalWidget_2);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 686, 21));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuAjouter = new QMenu(menuFichier);
        menuAjouter->setObjectName(QStringLiteral("menuAjouter"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menu->menuAction());
        menuFichier->addAction(actionQuitter);
        menuFichier->addAction(menuAjouter->menuAction());
        menuAjouter->addAction(actionPatient);
        menuAjouter->addAction(actionPersonnel_de_soin);
        menu->addAction(actionA_propos);
        mainToolBar->addAction(actionPatient);
        mainToolBar->addAction(actionPersonnel_de_soin);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
        actionPatient->setText(QApplication::translate("MainWindow", "Patient", Q_NULLPTR));
        actionPersonnel_de_soin->setText(QApplication::translate("MainWindow", "Personnel de soins", Q_NULLPTR));
        actionA_propos->setText(QApplication::translate("MainWindow", "A propos", Q_NULLPTR));
        firstNameEdit->setPlaceholderText(QApplication::translate("MainWindow", "First name", Q_NULLPTR));
        lastNameEdit->setPlaceholderText(QApplication::translate("MainWindow", "Last name", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Recherche de patients", Q_NULLPTR));
        planPushButton->setText(QApplication::translate("MainWindow", "Plan", Q_NULLPTR));
        savePushButton->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        pathPushButton->setText(QApplication::translate("MainWindow", "Browser", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Planification", Q_NULLPTR));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", Q_NULLPTR));
        menuAjouter->setTitle(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "?", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

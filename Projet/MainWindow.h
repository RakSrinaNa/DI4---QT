#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>

#include <QMainWindow>
#include <QSqlTableModel>
#include <QSortFilterProxyModel>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QKeyEvent>
#include <QDate>

#include "DBConnect.h"
#include "MySqlTableModel.h"
#include "MyDateItemDelegate.h"
#include "Schedule.h"
#include "TreeModel.h"
#include "NewCustomerDialog.h"
#include "NewStaffDialog.h"
#include "AboutDialog.h"
#include "TreeItem.h"
#include "MyDateSortFilterProxyModel.h"

namespace Ui
{
	class MainWindow;
}

/**
 * Main window.
 */
class MainWindow : public QMainWindow
{
Q_OBJECT

public:
	explicit MainWindow(QWidget * parent = 0);

	~MainWindow();

	/**
	 * Set the information text in the bottom bar.
	 * @param status The text to display.
	 * @param time The time to display time. 0 will show it until another message replaces it (default).
	 */
	void setStatusText(QString status, int time = 0);

private:
	Ui::MainWindow * ui;
	QSqlTableModel * model;
	TreeModel * model2;
	QSortFilterProxyModel * idModel;
	QSortFilterProxyModel * firstNameModel;
	QSortFilterProxyModel * lastNameModel;
    MyDateSortFilterProxyModel * dateFilterModel;
    bool editTable = false;
    bool editTree = false;

	/**
	 * Used to transform a string into one that start uppercase and the rest is lowercase. (used by slots from textedit)
	 * @param arg1 The string to modify.
	 */
	void upperCase_textEdited(const QString &arg1);

	/**
	 * Used to add ".txt" to the filename to save the schedule.
	 * @param arg1 The current file name.
	 */
	void textExtension_textEdited(const QString &arg1);

private slots:

	/**
	 * When the first name filter is edited.
	 * @param arg1 The cell content.
	 */
	void on_firstNameEdit_textEdited(const QString &arg1);

	/**
	 * When the last name filter is edited.
	 * @param arg1 The cell content.
	 */
	void on_lastNameEdit_textEdited(const QString &arg1);

	/**
	 * When a key is pressed.
	 * @param arg1 The key event.
	 */
	void keyPressEvent(QKeyEvent * event);

	/**
	 * When the schedule button is pressed.
	 */
	void on_planPushButton_clicked();

	/**
	 * When the Browse button is pressed.
	 */
	void on_pathPushButton_clicked();

	/**
	 * When the file name is edited.
	 * @param arg1 The cell content.
	 */
	void on_saveLineEdit_textEdited(const QString &arg1);

	/**
	 * When the save button is pressed.
	 */
	void on_savePushButton_clicked();

	/**
	 * When the exit menu is pressed.
	 */
	void on_actionExit_triggered();

	/**
	 * When the add customer menu is pressed.
	 */
	void on_actionCustomer_triggered();

	/**
	 * When the add staff menu is pressed.
	 */
	void on_actionStaff_triggered();

	/**
	 * When the about menu is pressed.
	 */
	void on_actionAbout_triggered();

	/**
	 * Called when an element in the customer table is modified.
	 * @param topLeft The top left coordinate of the edit area.
	 * @param bottomRight The bottom right coordinate of the edit area.
	 * @param roles The roles.
	 */
	void myon_tableView_data_changed(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles);

	/**
	 * Called when an element in the staff tree is modified.
	 * @param topLeft The top left coordinate of the edit area.
	 * @param bottomRight The bottom right coordinate of the edit area.
	 * @param roles The roles.
	 */
	void myon_treeView_data_changed(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles);

	/**
	 * When the id filter is edited.
	 * @param arg1 The cell content.
	 */
	void on_idLineEdit_textEdited(const QString &arg1);

    /**
     * When the first date filter is edited.
     * @param date The new date.
     */
	void on_startDate_userDateChanged(const QDate &date);

    /**
     * When the second date filter is edited.
     * @param date The new date.
     */
	void on_endDate_userDateChanged(const QDate &date);

    /**
     * When the button to show more columns in the table is clicked.
     */
    void on_editTablePushButton_clicked();

    /**
     * Show/hide the appropriated columns in the table.
     */
    void showEditTable();

    /**
     * When the button to show more columns in the tree is clicked.
     */
    void on_editTreePushButton_clicked();

signals:

	/**
	 * Signal to change the status bar text.
	 * @param status The text to set.
	 * //TODO Verify is useful.
	 */
    //void statusChanged(QString &status);
};

#endif // MAINWINDOW_H

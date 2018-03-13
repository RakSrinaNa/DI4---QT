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

#include "dbconnect.h"
#include "mysqltablemodel.h"
#include "mydateitemdelegate.h"

namespace Ui
{
	class MainWindow;
}

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
	QSortFilterProxyModel * idModel;
	QSortFilterProxyModel * firstNameModel;
	QSortFilterProxyModel * lastNameModel;
	
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
	 * When the first name is edited.
	 * @param arg1 The cell content.
	 */
	void on_firstNameEdit_textEdited(const QString &arg1);
	
	/**
	 * When the last name is edited.
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
	 * Called then an element in the customer table is modified.
	 * @param topLeft The top left coordinate of the edit area.
	 * @param bottomRight The bottom right coordinate of the edit area.
	 * @param roles The roles.
	 */
	void on_table_data_changed(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles);

signals:
	
	/**
	 * Signal to change the status bar text.
	 * @param status The text to set.
	 * //TODO Verify is useful.
	 */
	void statusChanged(QString &status);
};

#endif // MAINWINDOW_H

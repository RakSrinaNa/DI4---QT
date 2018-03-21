#include "MainWindow.h"
#include "ui_MainWindow.h"

extern DBConnect * db;

MainWindow::MainWindow(QWidget * parent) : QMainWindow (parent), ui(new Ui::MainWindow)
{
	qInfo() << "Opening main window";
	ui->setupUi(this);
	setFocusPolicy(Qt::StrongFocus); //Catch all the keyboard event
	setStatusText("You are connected");
	ui->tabWidget->tabBar()->setExpanding(true); //Tabs fill all width

	//Initialize tab 1 || SQLTable
	model = new MySqlTableModel(this, db->getDB()); //Model to avoid modifying column 0
	QObject::connect(model, SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&, const QVector<int>&)), this, SLOT(myon_tableView_data_changed(const QModelIndex&, const QModelIndex&, const QVector<int>&)));

	model->setTable("TClient");
	model->setEditStrategy(QSqlTableModel::OnRowChange); //Commit edits when a line is changed
	model->select();

	//Set columns names
	model->setHeaderData(0, Qt::Horizontal, tr("ID"));
	model->setHeaderData(1, Qt::Horizontal, tr("First Name"));
	model->setHeaderData(2, Qt::Horizontal, tr("Last name"));
	model->setHeaderData(3, Qt::Horizontal, tr("Address"));
	model->setHeaderData(4, Qt::Horizontal, tr("City"));
	model->setHeaderData(5, Qt::Horizontal, tr("Postal Code"));
	model->setHeaderData(6, Qt::Horizontal, tr("Comment"));
	model->setHeaderData(7, Qt::Horizontal, tr("Phone"));
	model->setHeaderData(8, Qt::Horizontal, tr("Date"));
	model->setHeaderData(9, Qt::Horizontal, tr("Length"));
	model->setHeaderData(10, Qt::Horizontal, tr("Priority"));

	//Filters to
	idModel = new QSortFilterProxyModel(this);
	firstNameModel = new QSortFilterProxyModel(this);
	lastNameModel = new QSortFilterProxyModel(this);
	dateFilterModel = new MyDateSortFilterProxyModel(this);

	ui->tableView->setModel(dateFilterModel);

	idModel->setSourceModel(model);
	idModel->setFilterKeyColumn(0);
	firstNameModel->setSourceModel(idModel);
	firstNameModel->setFilterKeyColumn(1);
	lastNameModel->setSourceModel(firstNameModel);
	lastNameModel->setFilterKeyColumn(2);
	dateFilterModel->setSourceModel(lastNameModel);
	dateFilterModel->setFilterKeyColumn(8);

	ui->startDate->setDate(QDate::currentDate());
	ui->endDate->setDate(QDate::currentDate());

	//dateFilterModel->setFilterMinimumDate(ui->startDate->date());
	//dateFilterModel->setFilterMaximumDate(ui->endDate->date());

	//Hide unwanted columns
	ui->tableView->setColumnHidden(0, false);
	ui->tableView->setColumnHidden(1, false);
	ui->tableView->setColumnHidden(2, false);
	ui->tableView->setColumnHidden(3, true);
	ui->tableView->setColumnHidden(4, true);
	ui->tableView->setColumnHidden(5, true);
	ui->tableView->setColumnHidden(6, true);
	ui->tableView->setColumnHidden(7, true);
	ui->tableView->setColumnHidden(8, false);
	ui->tableView->setColumnHidden(9, true);
	ui->tableView->setColumnHidden(10, true);

	ui->tableView->setAlternatingRowColors(true);

	//Make columns resize to the window's width
	//ui->tableView->setItemDelegateForColumn(8, new MyDateItemDelegate());
	ui->tableView->resizeColumnsToContents();
	for(int c = 0; c < ui->tableView->horizontalHeader()->count(); ++c)
	{
		ui->tableView->horizontalHeader()->setSectionResizeMode(c, QHeaderView::Stretch);
	}

	//Initialize tab 2
	model2 = new TreeModel(this); //Model to avoid modifying column
	QObject::connect(model2, SIGNAL(dataChanged(const QModelIndex, const QModelIndex, const QVector<int>)), this, SLOT(myon_treeView_data_changed(const QModelIndex, const QModelIndex, const QVector<int>)));
	ui->treeView->setModel(model2);

	ui->treeView->setColumnHidden(0, false);
	ui->treeView->setColumnHidden(1, false);
	ui->treeView->setColumnHidden(2, true);
	ui->treeView->setColumnHidden(3, true);
	ui->treeView->setAlternatingRowColors(true);

	for(int c = 0; c < ui->treeView->header()->count(); ++c)
	{
		ui->treeView->header()->setSectionResizeMode(c, QHeaderView::Stretch);
	}

	//Initialize tab 3
	ui->planDateEdit->setDate(QDate::currentDate());
	ui->pathLineEdit->setText(QDir::currentPath());


	//Shortcuts
	ui->actionCustomer->setShortcut(Qt::ALT + Qt::Key_C);
	ui->actionStaff->setShortcut(Qt::ALT + Qt::Key_S);
	ui->actionAbout->setShortcut(Qt::ALT + Qt::Key_A);
	ui->actionExit->setShortcut(Qt::ALT + Qt::Key_Q);
}

MainWindow::~MainWindow()
{
	qInfo() << "Destroying main window";
	delete ui;
}

void MainWindow::setStatusText(QString status, int time)
{
	qInfo() << "Status text changed to '" << status << " for " << time << "ms";
	ui->statusBar->showMessage(status, time);
}

void MainWindow::on_actionCustomer_triggered()
{
	qInfo() << "New customer button clicked";
	NewCustomerDialog newCustomer;
	if(newCustomer.exec() == QDialog::Accepted)
	{
		if(db->addCustomer(newCustomer.getCustomer()))
		{
			setStatusText("A new customer was added", 5000);
			model->select(); //Refresh view
		}
		else
			setStatusText("Failed to add a new customer", 5000);
	}
}

void MainWindow::on_actionStaff_triggered()
{
	qInfo() << "New staff button clicked";
	NewStaffDialog newStaff;
	if(newStaff.exec() == QDialog::Accepted)
	{
		if(db->addStaff(newStaff.getStaff()))
		{
			setStatusText("A new staff member was added", 5000);
			model2->reload(ui->treeView);
		}
		else
			setStatusText("Fail to add new staff member", 5000);
	}
}

void MainWindow::on_actionAbout_triggered()
{
	qInfo() << "About button clicked";
	AboutDialog aboutDialog;
	aboutDialog.exec();
}

void MainWindow::upperCase_textEdited(const QString &arg1)
{
	QString s = arg1;
	QString cap = s.left(1).toUpper(); //First to upper
	QString text = s.length() > 1 ? s.right(s.length() - 1).toLower() : ""; //The rest to lower
	qobject_cast<QLineEdit *>(sender())->setText(cap + text);
}

void MainWindow::textExtension_textEdited(const QString &arg1)
{
	int cursor = qobject_cast<QLineEdit *>(sender())->cursorPosition();
	QString oldText = arg1;
	QString newText = oldText;
	if(oldText == ".txt") //Clear empty name
		newText = "";
	if(!oldText.endsWith(".txt")) //Add extension
		newText = oldText + ".txt";

	qobject_cast<QLineEdit *>(sender())->setText(newText);
	qobject_cast<QLineEdit *>(sender())->setCursorPosition(cursor); //Put back the cursor where the user was typing
}

void MainWindow::on_firstNameEdit_textEdited(const QString &arg1)
{
	upperCase_textEdited(arg1);
	firstNameModel->setFilterRegExp(qobject_cast<QLineEdit *>(sender())->text());
}

void MainWindow::on_lastNameEdit_textEdited(const QString &arg1)
{
	upperCase_textEdited(arg1);
	lastNameModel->setFilterRegExp(qobject_cast<QLineEdit *>(sender())->text());
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
	switch(event->key())
	{
		//If delete is pressed
		case Qt::Key_Backspace:
		case Qt::Key_Delete:
		{
			qInfo() << "New delete key event";
			if(event->key() == Qt::Key_Backspace && !(QApplication::keyboardModifiers() & Qt::ControlModifier)) //If backspace for mac, verify the CMD key was pressed
			{
				break;
			}
			if(ui->tabWidget->currentIndex() == 0) //If in the first tab (sql table)
			{
				int current = ui->tableView->selectionModel()->currentIndex().row();
				if(current != -1) //If a row is selected
				{
					model->removeRow(current);
					model->submitAll();
					model->select();

					int total = ui->tableView->model()->rowCount();
					if(current >= total - 1)
						current = total - 1;
					ui->tableView->selectRow(current); //Select closest row
				}
			}
			else if(ui->tabWidget->currentIndex() == 1) //If in the second tab (tree)
			{
				QModelIndex current = ui->treeView->selectionModel()->currentIndex();
				if(current.row() != -1) //If a row is selected
				{
					TreeItem * item = model2->getItem(ui->treeView->selectionModel()->currentIndex());

					bool result = true;
					QModelIndex index = current;
					int depth = 0;
					while(index.parent().isValid())
					{
					  index = index.parent();
					  depth++;
					}
					if(depth == 0) //Removing type
					{
						if(0)
						{ //Du coup on m'a dit faut pas tout cramer
							if((result = db->removeResourceType(item->data(2).toInt())))
							{
								result &= model2->removeRow(current.row(), current.parent());
								qInfo() << "Deleted type";
							}
						}
						else
						{
							if((result = db->removeAllStaffOfType(item->data(2).toInt())))
							{
								while(item->childCount() > 0)
									result &= model2->removeRow(0, current);
								qInfo() << "Deleted type";
							}
						}

					}
					else if(depth == 1) //Removing staff
					{
						if((result = db->removeStaff(item->data(2).toInt())))
						{
							result &= model2->removeRow(current.row(), current.parent());
							std::cout << "Deleted staff" << std::endl;
						}
					}

					if(result)
					{
						setStatusText("Element deleted", 2000);
					}
					else
					{
						setStatusText("Error deleting data");
					}
				}
			}
			break;
		}
	}
	event->accept();
}

void MainWindow::on_planPushButton_clicked()
{
	qInfo() << "Plan button clicked";
	QDate date = ui->planDateEdit->date();
	QString s("");

	//Get all customers
	QList<Customer *> * listCustomers = db->getClientsFromDate(date);

	if(listCustomers->size() == 0)
		s += "No customer for " + date.toString("dd MMMM yyyy");

	else{
		QList<Staff *> * listStaff = db->getAllStaff();

		Schedule schedule = Schedule(listStaff);

		//Schedule all the customers
		for(int i = 0; i < listCustomers->size(); i++)
			schedule.addCustomer(listCustomers->at(i));

		s = schedule.toHtmlString();

		//Free all staff members
		for(int i = 0; i < listStaff->size(); i++)
			delete listStaff->at(i);
		delete listStaff;

		ui->saveLineEdit->setText("Schedule " + date.toString("dd MMMM yyyy") + ".txt");
		ui->saveLineEdit->setStyleSheet("background-color:white;");

	}

	ui->planTextBrowser->setStyleSheet("background-color:white;");
	ui->planTextBrowser->setText(s);

	//Free all customers
	for(int i = 0; i < listCustomers->size(); i++)
		delete listCustomers->at(i);
	delete listCustomers;

}

void MainWindow::on_pathPushButton_clicked()
{
	qInfo() << "Browser button clicked";
	QString oldDir = ui->pathLineEdit->text();
	QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), oldDir);
	ui->pathLineEdit->setText(dir);
}

void MainWindow::on_saveLineEdit_textEdited(const QString &arg1)
{
	textExtension_textEdited(arg1);
	if(!ui->saveLineEdit->text().isEmpty())
		ui->saveLineEdit->setStyleSheet("background-color:white;");
}

void MainWindow::on_savePushButton_clicked()
{
	qInfo() << "Save button clicked";
	QMessageBox message(this);
	message.setWindowTitle("Informations");

	bool ok = true;

	if(!(ok = !ui->saveLineEdit->text().isEmpty())) //If the file mane is empty
		ui->saveLineEdit->setStyleSheet("background-color:red;");
	if(!(ok = !ui->planTextBrowser->toPlainText().isEmpty())) //If no scheduling info is present.
		ui->planTextBrowser->setStyleSheet("background-color:red;");

	if(ok) //If everything needed is present
	{
		QFile file(ui->pathLineEdit->text() + "/" + ui->saveLineEdit->text());
		if(file.open(QIODevice::WriteOnly | QIODevice::Text)) //Write into file
		{
			QTextStream stream(&file);
			stream << ui->planTextBrowser->toPlainText();
			file.close();
			message.setText("Wrote successfully into file.");
		}
		else
		{
			message.setText("Failed to write into file.");
		}
		message.exec();
	}
}

void MainWindow::on_actionExit_triggered()
{
	qInfo() << "Exit button clicked";
	close();
}

void MainWindow::myon_tableView_data_changed(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles)
{
	qInfo() << "Table view data changed";
	(void) roles; //Unused warning taken down
	if(topLeft.column() == bottomRight.column() && topLeft.row() == bottomRight.row()) //If we edited only one cell
	{
		QVariant q = model->data(topLeft);
		switch(topLeft.column())
		{
			//Capitalize the first letter
			case 1: //First name
			case 2: //Last name
			{
				QString s = q.toString();
				QString cap = s.left(1).toUpper();
				QString text = s.length() > 1 ? s.right(s.length() - 1).toLower() : "";
				if(!QRegularExpression("[A-Za-zéè '-]+").match(cap + text).hasMatch())
				{
					setStatusText("Invalid name, change it!");
					model->revertRow(topLeft.row());
				}
				else
					model->setData(topLeft, (cap + text));
				break;
			}

			case 4: //City
			{
				QString s = q.toString();
				QString cap = s.left(1).toUpper();
				QString text = s.length() > 1 ? s.right(s.length() - 1).toLower() : "";
				if(!QRegularExpression("[A-Za-zéèà '-/]+").match(cap + text).hasMatch())
				{
					setStatusText("Invalid name, change it!");
					model->revertRow(topLeft.row());
				}
				else
					model->setData(topLeft, (cap + text));
				break;
			}

			case 3: //Address
			{
				QString s = q.toString();
				std::cout << s.toStdString() << std::endl;
				if(!QRegularExpression("[1-9]\\d* [A-Za-zéè '-]+").match(s).hasMatch())
				{
					setStatusText("Invalid address, change it!");
					model->revertRow(topLeft.row());
				}
				else
					model->setData(topLeft, s);

				break;
			}

			case 5: //Postal code
			{
				QString s = q.toString();
				if(!QRegularExpression("\\d{5}").match(s).hasMatch())
				{
					setStatusText("Invalid postal code, change it!");
					model->revertRow(topLeft.row());
				}
				else
					model->setData(topLeft, q.toInt());

				break;
			}

			case 7: //Phone
			{
			QString s = q.toString();
			if(!QRegularExpression("\\d{10}").match(s).hasMatch())
			{
				setStatusText("Invalid phone number, change it!");
				model->revertRow(topLeft.row());
			}
			else
				model->setData(topLeft, q.toInt());

				break;
			}

			case 9: //Duration
			{
				if(!QRegularExpression("[1-9]+\\d*").match(q.toString()).hasMatch() || q.toInt() <= 0)
				{
					setStatusText("Invalid duration, change it!");
					model->revertRow(topLeft.row());
				}
				else
					model->setData(topLeft, q.toInt());

				break;
			}

			case 10: //Priority
			{
			if(!QRegularExpression("[1-5]{1}").match(q.toString()).hasMatch())
			{
				setStatusText("Invalid priority, change it!");
				model->revertRow(topLeft.row());
			}
			else
				model->setData(topLeft, q.toInt());

				break;
			}

			//Verify format and if not in the past
			case 8: //Date
			{
				QDate date = QDate::fromString(q.toString(), "yyyy-MM-dd");
				if(date < QDate::currentDate())
				{
					model->revertRow(topLeft.row());
					setStatusText("Wrong date format or date in the past");
				}
				break;
			}
		}
	}
}

void MainWindow::on_idLineEdit_textEdited(const QString &arg1)
{
	QRegExp re("\\d*");
	if(re.exactMatch(arg1))
		idModel->setFilterRegExp(arg1);
	else
		qobject_cast<QLineEdit *>(sender())->setText(arg1.left(arg1.length() - 1));
}

void MainWindow::myon_treeView_data_changed(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles)
{
	qInfo() << "Tree view data changed";
	(void) roles; //Unused warning taken down
	if(topLeft.column() == bottomRight.column() && topLeft.row() == bottomRight.row()) //If we edited only one cell
	{
		QModelIndex index = topLeft;
		TreeItem * item = model2->getItem(topLeft);
		int resID = item->data(3).toInt();
		int depth = 0;
		while ( index.parent().isValid() )
		{
		  index = index.parent();
		  depth++;
		}
		if(depth == 0) //Type changed
		{
			if(topLeft.column() == 0)
			{
				if(item->data(topLeft.column()).toString().length() == 0)
				{
					setStatusText("Invalid resource name, change it!");
				}
				else if(db->changeResourceName(resID, item->data(topLeft.column()).toString()))
				{
					setStatusText("Resource name changed", 2000);
					model2->reload(ui->treeView);
				}
				else
				{
					setStatusText("The resource name failed to be changed, try again later ;)");
				}
			}
			else
			{
				item->setData(topLeft.column(), "");
			}
		}
		else if(depth == 1) //Staff changed
		{
			switch(topLeft.column())
			{
				//Capitalize element
				case 0: //First name
				case 1: //Last name
				{
					QString s = item->data(topLeft.column()).toString();
					QString cap = s.left(1).toUpper();
					QString text = s.length() > 1 ? s.right(s.length() - 1).toLower() : "";
					if(!QRegularExpression("[A-Za-zéèà '-]+").match(cap + text).hasMatch())
					{
						setStatusText("Invalid staff name, change it!");
					}
					else if(db->changeStaffName(resID, item->data(0).toString(), item->data(1).toString()))
					{
						setStatusText("Value changed", 2000);
					}
					else
					{
						setStatusText("Failed to execute query, try again later ;)");
					}
					break;
				}

				case 2: //Resource type
				{
					ResourceType * type = db->getType(item->data(topLeft.column()).toString());
					if(type == nullptr)
					{
						setStatusText("Invalid resource name, change it!");
					}
					else
					{
						if(db->changeStaffResource(resID, type->getId()))
						{
							setStatusText("Value changed", 2000);
							model2->reload(ui->treeView);
						}
						else
						{
							setStatusText("Failed to execute query, try again later ;)");
						}
						delete type;
					}
				}
			}
		}
	}
}

void MainWindow::on_startDate_userDateChanged(const QDate &date)
{
	dateFilterModel->setFilterMinimumDate(date);
}

void MainWindow::on_endDate_userDateChanged(const QDate &date)
{
	dateFilterModel->setFilterMaximumDate(date);
}

void MainWindow::on_editTablePushButton_clicked()
{
	editTable = !editTable;
	showEditTable();
}

void MainWindow::showEditTable()
{
	ui->tableView->setColumnHidden(3, !editTable);
	ui->tableView->setColumnHidden(4, !editTable);
	ui->tableView->setColumnHidden(5, !editTable);
	ui->tableView->setColumnHidden(6, !editTable);
	ui->tableView->setColumnHidden(7, !editTable);
	ui->tableView->setColumnHidden(9, !editTable);
	ui->tableView->setColumnHidden(10, !editTable);

	if(editTable)
		ui->editTablePushButton->setText("Hide additional columns");
	else
		ui->editTablePushButton->setText("Show hidden columns");

}

void MainWindow::on_editTreePushButton_clicked()
{
	editTree = !editTree;
	showEditTree();
}

void MainWindow::showEditTree()
{
	ui->treeView->setColumnHidden(2, !editTree);
	ui->treeView->setColumnHidden(3, !editTree);

	if(editTree)
		ui->editTreePushButton->setText("Hide additional columns");
	else
		ui->editTreePushButton->setText("Show hidden columns");

}

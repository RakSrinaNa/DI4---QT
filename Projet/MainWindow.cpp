#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newpatientdialog.h"
#include "newstaffdialog.h"
#include "AboutDialog.h"

extern DBConnect * db;

MainWindow::MainWindow(QWidget * parent) : QMainWindow (parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	setFocusPolicy(Qt::StrongFocus); //Catch all the keyboard event
	setWindowTitle("Application");
	setStatusText("You are connected");
	ui->tabWidget->tabBar()->setExpanding(true); //Tabs fill all width
	
	//Initialize tab 1 || SQLTable
	model = new MySqlTableModel(this, db->getDB()); //Model to avoid modifying column 0
	QObject::connect(model, SIGNAL(dataChanged(const QModelIndex, const QModelIndex, const QVector<int>)), this, SLOT(on_table_data_changed(const QModelIndex, const QModelIndex, const QVector<int>)));
	
	model->setTable("TClient");
	model->setEditStrategy(QSqlTableModel::OnRowChange); //Commit edits when a line is changed
	model->select();
	
	//Set columns names
	model->setHeaderData(0, Qt::Horizontal, tr("Id"));
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
	
	ui->tableView->setModel(lastNameModel);
	
	idModel->setSourceModel(model);
	idModel->setFilterKeyColumn(0);
	firstNameModel->setSourceModel(idModel);
	firstNameModel->setFilterKeyColumn(1);
	lastNameModel->setSourceModel(firstNameModel);
	lastNameModel->setFilterKeyColumn(2);
	
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
	
	//Make columns resize to the window's width
	//ui->tableView->setItemDelegateForColumn(8, new MyDateItemDelegate());
	ui->tableView->resizeColumnsToContents();
	for(int c = 0; c < ui->tableView->horizontalHeader()->count(); ++c)
	{
		ui->tableView->horizontalHeader()->setSectionResizeMode(c, QHeaderView::Stretch);
	}
	
	//connect(ui->submitButton, SIGNAL(clicked()), this, SLOT(submit()));
	//connect(ui->revertButton, SIGNAL(clicked()), model, SLOT(revertAll()));
	
	//Initialize tab 2
	//TODO
	
	//Initialize tab 3
	ui->planDateEdit->setDate(QDate::currentDate());
	ui->pathLineEdit->setText(QDir::currentPath());
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::setStatusText(QString status, int time)
{
	ui->statusBar->showMessage(status, time);
}

void MainWindow::on_actionCustomer_triggered()
{
	NewCustomerDialog newCustomer;
	if(newCustomer.exec() == QDialog::Accepted)
	{
		if(db->addCustomer(newCustomer.getPatient()))
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
	NewStaffDialog newStaff;
	if(newStaff.exec() == QDialog::Accepted)
	{
		if(db->addStaff(newStaff.getStaff()))
			setStatusText("A new staff member was added", 5000);
		else
			setStatusText("Fail to add new staff member", 5000);
	}
}

void MainWindow::on_actionAbout_triggered()
{
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
		//If deleting element in the sql table
		case Qt::Key_Backspace:
		case Qt::Key_Delete:
		{
			if(event->key() == Qt::Key_Backspace && !(QApplication::keyboardModifiers() & Qt::ControlModifier)) //If backspace for mac, verify the CMD key was pressed
			{
				break;
			}
			
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
			break;
		}
		
		//TODO delete
		case Qt::Key_0:
			QList<Customer *> * list = db->getClientsFromDate(ui->planDateEdit->date());
			for(int i = 0; i < list->size(); i++)
			{
				std::cout << list->at(i)->toString().toStdString() << std::endl;
			}
			break;
	}
	event->accept();
}

void MainWindow::on_planPushButton_clicked()
{
	QDate date = ui->planDateEdit->date();
	QString s("");
	
	QList<Customer *> * listPatient = db->getClientsFromDate(date);
	
	if(listPatient->size() == 0)
		s += "No client for " + date.toString("dd MMMM yyyy");
	
	for(int i = 0; i < listPatient->size(); i++)
		s += listPatient->at(i)->toString() + "<br />";
	
	ui->planTextBrowser->setStyleSheet("background-color:white;");
	ui->planTextBrowser->setText(s);
}

void MainWindow::on_pathPushButton_clicked()
{
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
		if(file.open(QIODevice::WriteOnly)) //Write into file
		{
			QTextStream stream(&file);
			stream << ui->planTextBrowser->toPlainText();
			file.close();
			message.setText("Wrote succesfully into file.");
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
	close();
}

void MainWindow::on_table_data_changed(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles)
{
	(void) roles; //Unused warning taken down
	if(topLeft.column() == bottomRight.column() && topLeft.row() == bottomRight.row()) //If we edited only one cell
	{
		QVariant q = model->data(topLeft);
		switch(topLeft.column())
		{
			//If columns related to the name, capitalize the first letter
			case 1:
			case 2:
			{
				QString s = q.toString();
				QString cap = s.left(1).toUpper();
				QString text = s.length() > 1 ? s.right(s.length() - 1).toLower() : "";
				model->setData(topLeft, (cap + text));
				break;
			}
			//If date column, verify format and if not in the past
			case 8:
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
    idModel->setFilterRegExp(arg1);
}

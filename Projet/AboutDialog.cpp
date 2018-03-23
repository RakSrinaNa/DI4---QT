#include "AboutDialog.h"
#include "ui_AboutDialog.h"

AboutDialog::AboutDialog(QWidget * parent) : QDialog(parent), ui(new Ui::AboutDialog)
{
    qDebug() << "Opening About dialog" ;
	ui->setupUi(this);
	this->setWindowTitle("About");
}

AboutDialog::~AboutDialog()
{
    qDebug() << "Destroying About dialog" ;
	delete ui;
}

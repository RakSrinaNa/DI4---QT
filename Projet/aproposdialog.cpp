#include "aproposdialog.h"
#include "ui_aproposdialog.h"

AboutDialog::AboutDialog(QWidget * parent) : QDialog(parent), ui(new Ui::AProposDialog)
{
	ui->setupUi(this);
	this->setWindowTitle("About");
}

AboutDialog::~AboutDialog()
{
	delete ui;
}

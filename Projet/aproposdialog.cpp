#include "aproposdialog.h"
#include "ui_aproposdialog.h"

AProposDialog::AProposDialog(QWidget * parent) : QDialog(parent), ui(new Ui::AProposDialog)
{
	ui->setupUi(this);
	this->setWindowTitle("About");
}

AProposDialog::~AProposDialog()
{
	delete ui;
}

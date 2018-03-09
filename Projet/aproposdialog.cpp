#include "aproposdialog.h"
#include "ui_aproposdialog.h"

AProposDialog::AProposDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AProposDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("A propos");
}

AProposDialog::~AProposDialog()
{
    delete ui;
}

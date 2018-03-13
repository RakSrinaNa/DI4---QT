#ifndef APROPOSDIALOG_H
#define APROPOSDIALOG_H

#include <QDialog>

namespace Ui
{
	class AProposDialog;
}

/**
 * About window.
 */
class AboutDialog : public QDialog
{
	Q_OBJECT

public:
	explicit AboutDialog(QWidget * parent = 0);
	
	~AboutDialog();

private:
	Ui::AProposDialog * ui;
};

#endif // APROPOSDIALOG_H

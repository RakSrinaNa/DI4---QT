#ifndef APROPOSDIALOG_H
#define APROPOSDIALOG_H

#include <QDialog>
#include <QDebug>

namespace Ui
{
    class AboutDialog;
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
    Ui::AboutDialog * ui;
};

#endif // APROPOSDIALOG_H

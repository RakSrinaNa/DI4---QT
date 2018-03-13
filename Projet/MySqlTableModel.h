#ifndef MYSQLTABLEMODEL_H
#define MYSQLTABLEMODEL_H

#include<QSqlTableModel>

/**
 * A model to forbid editing the first column (ID).
 */
class MySqlTableModel : public QSqlTableModel
{
public:
	MySqlTableModel(QObject * parent = Q_NULLPTR, QSqlDatabase db = QSqlDatabase());
	
	Qt::ItemFlags flags(const QModelIndex &index) const;
};

#endif // MYSQLTABLEMODEL_H

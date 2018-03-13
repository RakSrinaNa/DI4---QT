#ifndef MYSQLTABLEMODEL_H
#define MYSQLTABLEMODEL_H

#include<QSqlTableModel>

class MySqlTableModel : public QSqlTableModel
{
public:
    MySqlTableModel(QObject *parent = Q_NULLPTR, QSqlDatabase db = QSqlDatabase());

    Qt::ItemFlags flags(const QModelIndex &index) const {
            if(index.column() == 0)
                return Qt::ItemIsEnabled|Qt::ItemIsSelectable;
            else
                return Qt::ItemIsEnabled|Qt::ItemIsSelectable|Qt::ItemIsEditable;
        }
};

#endif // MYSQLTABLEMODEL_H

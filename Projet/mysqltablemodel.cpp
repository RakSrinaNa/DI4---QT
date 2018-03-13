#include "mysqltablemodel.h"

MySqlTableModel::MySqlTableModel(QObject *parent, QSqlDatabase db) : QSqlTableModel(parent, db)
{

}

Qt::ItemFlags MySqlTableModel::flags(const QModelIndex &index) const {
    if(index.column() == 0)
        return Qt::ItemIsEnabled|Qt::ItemIsSelectable;
    else
        return Qt::ItemIsEnabled|Qt::ItemIsSelectable|Qt::ItemIsEditable;
}


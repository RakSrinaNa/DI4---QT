#include "mydateitemdelegate.h"

MyDateItemDelegate::MyDateItemDelegate(QObject *parent) : QItemDelegate(parent)
{

}

QWidget* MyDateItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    (void)option;
    (void)index;
    QDateEdit * dateEdit = new QDateEdit(parent);

    return dateEdit;
}

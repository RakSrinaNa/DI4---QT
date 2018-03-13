#include <QtWidgets>
#include "MyDateItemDelegate.h"

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

void MyDateItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QDateEdit *dateEdit = static_cast<QDateEdit*>(editor);
    QString value = index.model()->data(index, Qt:: EditRole).toString();
    dateEdit->setDate(QDate::fromString(value));
}

void MyDateItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QDateEdit *dateEdit = static_cast<QDateEdit*>(editor);
    model->setData(index, dateEdit->date().toString("yyyy-MM-dd"), Qt::EditRole);
}

void MyDateItemDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}

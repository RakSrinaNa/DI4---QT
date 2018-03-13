#ifndef MYDATEITEMDELEGATE_H
#define MYDATEITEMDELEGATE_H

#include <QItemDelegate>
#include <QDateEdit>

class MyDateItemDelegate : public QItemDelegate
{
public:
    MyDateItemDelegate(QObject *parent = Q_NULLPTR);
    using QItemDelegate::createEditor;
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index);
};

#endif // MYDATEITEMDELEGATE_H

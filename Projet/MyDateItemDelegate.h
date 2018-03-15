#ifndef MYDATEITEMDELEGATE_H
#define MYDATEITEMDELEGATE_H

#include <QItemDelegate>
#include <QDateEdit>

/**
 * Item delegate to show a date edit when changing date in the table.
 */
class MyDateItemDelegate : public QItemDelegate
{
public:
	MyDateItemDelegate(QObject * parent = Q_NULLPTR);
	
	using QItemDelegate::createEditor;
	
	QWidget * createEditor(QWidget * parent, const QStyleOptionViewItem &option, const QModelIndex &index);
	
	void setEditorData(QWidget * editor, const QModelIndex &index) const;
	
	void setModelData(QWidget * editor, QAbstractItemModel * model, const QModelIndex &index) const;
	
	void updateEditorGeometry(QWidget * editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // MYDATEITEMDELEGATE_H

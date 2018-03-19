#ifndef MYDATESORTFILTERPROXYMODEL_H
#define MYDATESORTFILTERPROXYMODEL_H

#include <QObject>
#include <QSortFilterProxyModel>
#include <QDate>
#include <QVariant>

class MyDateSortFilterProxyModel : public QSortFilterProxyModel
{
public:
	MyDateSortFilterProxyModel(QObject * parent = Q_NULLPTR);

	QDate filterMinimumDate() const { return minDate; }
	void setFilterMinimumDate(const QDate &date);

	QDate filterMaximumDate() const { return maxDate; }
	void setFilterMaximumDate(const QDate &date);

protected:
	bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;
	bool lessThan(const QModelIndex &left, const QModelIndex &right) const override;

private:
	bool dateInRange(const QDate &date) const;

	QDate minDate;
	QDate maxDate;
};

#endif // MYDATESORTFILTERPROXYMODEL_H

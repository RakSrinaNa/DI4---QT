#include "MyDateSortFilterProxyModel.h"

MyDateSortFilterProxyModel::MyDateSortFilterProxyModel(QObject * parent) : QSortFilterProxyModel(parent)
{

}

bool MyDateSortFilterProxyModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
 {
	 QVariant leftData = sourceModel()->data(left);
	 QVariant rightData = sourceModel()->data(right);

	 return leftData.toDate() < rightData.toDate();
}

bool MyDateSortFilterProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
	return dateInRange(sourceModel()->data(sourceModel()->index(sourceRow, filterKeyColumn(), sourceParent)).toDate());
}

bool MyDateSortFilterProxyModel::dateInRange(const QDate &date) const
{
	return (!minDate.isValid() || date > minDate) && (!maxDate.isValid() || date < maxDate);
}

void MyDateSortFilterProxyModel::setFilterMinimumDate(const QDate &date)
{
	minDate = date;
	invalidateFilter();
}

void MyDateSortFilterProxyModel::setFilterMaximumDate(const QDate &date)
{
	maxDate = date;
	invalidateFilter();
}

#include "Test.h"

#include <QString>
#include <QtGlobal>

Test::Test(QObject *parent)
	: QObject{parent}
{
    myTreeModel = new QStandardItemModel( this );
    for( auto i = 0; i < 3; ++i )
    {
        QString t1 = std::to_string( i ).c_str();
        auto row = new QStandardItem( t1  );
        for( auto j = 0; j < 3; ++j )
        {
            QString t2 = t1 + std::to_string( j ).c_str();
            row->appendRow( new QStandardItem( t2 ) );
        }
        myTreeModel->appendRow( row );
    }

    mySelectionModel = new QItemSelectionModel( myTreeModel, this );
}

QVariant Test::getTreeModel()
{
    return QVariant::fromValue( myTreeModel );
}

QVariant Test::getSelectionModel()
{
    return QVariant::fromValue( mySelectionModel );
}

namespace
{
    void SelectAllItems( QStandardItem* item, QItemSelectionModel* selectionModel )
    {
        for( auto r = 0; r < item->rowCount(); ++r )
            SelectAllItems( item->child( r ), selectionModel );
        if( !item->hasChildren() )
            selectionModel->select( item->index(),  QItemSelectionModel::Select | QItemSelectionModel::Rows  );
    }
}

void Test::selectAll()
{
    qDebug() << "selectAll()";
    for( auto r = 0; r < myTreeModel->rowCount(); ++r )
        SelectAllItems( myTreeModel->item( r ), mySelectionModel );
}
void Test::deselectOne()
{
    qDebug() << "deselectSome()";

    auto selectedBefore = mySelectionModel->selectedRows().count();
    Q_ASSERT( selectedBefore == 9 );

    auto topRow = myTreeModel->item( 1 );
    auto selectedRow = topRow->child( 0 );

    qDebug() << "selectedBefore: " << selectedBefore;
    mySelectionModel->select( selectedRow->index(), QItemSelectionModel::Toggle | QItemSelectionModel::Rows );

    auto selectedAfter = mySelectionModel->selectedRows().count();
    qDebug() << "selectedAfter: " << selectedAfter;

    Q_ASSERT( selectedAfter == 8 );
}

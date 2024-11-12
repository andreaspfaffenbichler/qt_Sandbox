#pragma once

#include <QObject>
#include <QQuickPaintedItem>
#include <QQuickPaintedItem>
#include <QItemSelectionModel>
#include <QStandardItemModel>

class Test : public QObject
{
	Q_OBJECT

public:
	explicit Test(QObject *parent = nullptr);

public slots:
    QVariant getTreeModel();
    QVariant getSelectionModel();
    void selectAll();
    void deselectOne();

private:
    QStandardItemModel* myTreeModel = nullptr;
    QItemSelectionModel* mySelectionModel = nullptr;
};



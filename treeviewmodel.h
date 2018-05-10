#ifndef TREEVIEWMODEL_H
#define TREEVIEWMODEL_H

#include <QAbstractItemModel>

class TreeViewModel : public QAbstractItemModel
{
Q_OBJECT
public:
    TreeViewModel(QObject *parent=nullptr){}
    ~TreeViewModel(){}

    void appendChild(const QModelIndex& idx);
    QVariant data(const QModelIndex& idx);
};


#endif // TREEVIEWMODEL_H

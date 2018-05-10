#ifndef TREEVIEW_FILESYSTEM_MODEL_H
#define TREEVIEW_FILESYSTEM_MODEL_H

#include <QAbstractItemModel>
#include <QStandardItem>

#include "treeview_item.h"

class TreeViewFileSystemModel : public QAbstractItemModel
{
    Q_OBJECT
    enum ItemRoles{
        Name=Qt::UserRole + 1,
        Permissions
    };
public:
    TreeViewFileSystemModel(QObject *parent=nullptr);

    virtual int columnCount(const QModelIndex &parent) const override;
    virtual QModelIndex index(int row, int column, const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QModelIndex parent(const QModelIndex &child) const override;
    virtual int rowCount(const QModelIndex &parent) const override;

private:
    TreeViewItem *m_rootItem;
};

#endif // TREEVIEW_FILESYSTEM_MODEL_H

#include "treeview_filesystem_model.h"

TreeViewFileSystemModel::TreeViewFileSystemModel(QObject* parent):
    m_rootItem(new TreeViewItem())
{
    //TEST CODE
    QList<QVariant> list;
    list.append("Folder1");
    list.append("desc folder");

    TreeViewItem* item = new TreeViewItem(list, m_rootItem);
    m_rootItem->appendChild(item);
}

int TreeViewFileSystemModel::columnCount(const QModelIndex &parent) const
{
    return 2;

    if(!parent.isValid())
    {
        return 0;
    }

    return 0;
}

QModelIndex TreeViewFileSystemModel::index(int row, int column, const QModelIndex &parent) const
{
    if(!hasIndex(row, column,parent))
        return QModelIndex();

    return QModelIndex();
}

QVariant TreeViewFileSystemModel::data(const QModelIndex &index, int role) const
{
    switch (role) {
    case ItemRoles::Name:
        return "TheName";
        break;
    case ItemRoles::Permissions:
        return "ThePermissions";
    default:
        break;
    }
}

QModelIndex TreeViewFileSystemModel::parent(const QModelIndex &child) const
{
    if(!child.isValid())
    {
        return QModelIndex();
    }

    return QModelIndex();

}

int TreeViewFileSystemModel::rowCount(const QModelIndex &parent) const
{
    return 0;
}

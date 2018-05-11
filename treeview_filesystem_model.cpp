#include "treeview_filesystem_model.h"

TreeViewFileSystemModel::TreeViewFileSystemModel(QObject* parent)
{
    //TEST CODE
    QList<QVariant> list;
    list.append("Folder1");
    list.append("desc folder");
    m_rootItem = new TreeViewItem(list,nullptr);

    TreeViewItem* item = new TreeViewItem(list, m_rootItem);
    m_rootItem->appendChild(item);
}

int TreeViewFileSystemModel::columnCount(const QModelIndex &parent) const
{
    return m_rootItem->columnCount();
}

QModelIndex TreeViewFileSystemModel::index(int row, int column, const QModelIndex &parent) const
{
    if(!hasIndex(row, column,parent))
        return QModelIndex();

    TreeViewItem* item;
    if(!parent.isValid())
        item = m_rootItem;
    else
        item = static_cast<TreeViewItem*>(parent.internalPointer());

    TreeViewItem* child = item->child(row);
    if(child)
        return createIndex(row, column, child);

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

    TreeViewItem* item = static_cast<TreeViewItem*>(child.internalPointer());
    if(!item)
        return QModelIndex();

    TreeViewItem* parentItem = item->parent();
    if(parentItem == m_rootItem)
        return QModelIndex();

    return createIndex(parentItem->row(),0, parentItem);
}

int TreeViewFileSystemModel::rowCount(const QModelIndex &parent) const
{
    if(!parent.isValid())
        return m_rootItem->childCount();

    return m_rootItem->childCount();
}

QHash<int, QByteArray> TreeViewFileSystemModel::roleNames()
{
    QHash<int, QByteArray> names(QAbstractItemModel::roleNames());
    names[ItemRoles::Name] = "Name";
    names[ItemRoles::Permissions] = "Permissions";

    return names;
}

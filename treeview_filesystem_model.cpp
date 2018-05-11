#include "treeview_filesystem_model.h"

TreeViewFileSystemModel::TreeViewFileSystemModel(QObject* parent)
{
    //TEST CODE
    QList<QVariant> list;
    list.append("Folder1");
    list.append("desc folder");
    m_rootItem = new TreeViewItem(list,nullptr);

    QList<QVariant> sublist;
    sublist.append("Node1");
    sublist.append("theSubNode");
    TreeViewItem* item = new TreeViewItem(sublist, m_rootItem);

    QList<QVariant> sublist2;
    sublist2.append("Node2");
    sublist2.append("subNode2");
    TreeViewItem* item2 = new TreeViewItem(sublist2, m_rootItem);

    QList<QVariant> sublist3;
    sublist3.append("Node3");
    sublist3.append("SubNode3");
    item2->appendChild(new TreeViewItem(sublist3, item2));

    m_rootItem->appendChild(item);
    m_rootItem->appendChild(item2);
}

int TreeViewFileSystemModel::columnCount(const QModelIndex &parent) const
{
    return m_rootItem->columnCount();
}

/*
 * Returns the index of the item in the model specified by the given row, column and parent index.
 * When reimplementing this function in a subclass, call createIndex() to generate model indexes that other components can use to refer to items in your model.
*/
QModelIndex TreeViewFileSystemModel::index(int row, int column, const QModelIndex &parent) const
{
    if(!hasIndex(row, column,parent))
        return QModelIndex();

    TreeViewItem* parentItem;
    if(!parent.isValid())
        parentItem = m_rootItem;
    else
        parentItem = static_cast<TreeViewItem*>(parent.internalPointer());

    TreeViewItem* child = parentItem->child(row);
    if(child)
        return createIndex(row, column, child);

    return QModelIndex();
}

QVariant TreeViewFileSystemModel::data(const QModelIndex &index, int role) const
{
    TreeViewItem* item = static_cast<TreeViewItem*>(index.internalPointer());

    if(!item)
        return "Error";

    switch (role) {
    case ItemRoles::Name:
        return item->data(0);
        break;
    case ItemRoles::CreateDate:
        return item->data(1);
        break;
    default:
        return "DefaultRole";
        break;
    }
}

/*
 * Returns the parent of the model item with the given index. If the item has no parent, an invalid QModelIndex is returned.
 * A common convention used in models that expose tree data structures is that only items in the first column have children.
 * For that case, when reimplementing this function in a subclass the column of the returned QModelIndex would be 0.
 * When reimplementing this function in a subclass, be careful to avoid calling QModelIndex member functions, such as QModelIndex::parent(),
 * since indexes belonging to your model will simply call your implementation, leading to infinite recursion.
*/
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
    int row = 0;
    if(parentItem != m_rootItem)
        row = parentItem->row();

    return createIndex(row,0, parentItem);
}

int TreeViewFileSystemModel::rowCount(const QModelIndex &parent) const
{
    if(!parent.isValid())
        return m_rootItem->childCount();

    TreeViewItem* parentItem = static_cast<TreeViewItem*>(parent.internalPointer());
    if(!parentItem)
        return 0;

    return parentItem->childCount();
}

QHash<int, QByteArray> TreeViewFileSystemModel::roleNames() const
{
    QHash<int, QByteArray> names(QAbstractItemModel::roleNames());
    names[ItemRoles::Name] = "Name";
    names[ItemRoles::CreateDate] = "CreateDate";

    return names;
}

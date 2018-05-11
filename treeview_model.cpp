#include "treeview_model.h"
#include <QDir>
#include <QDateTime>

TreeViewModel::TreeViewModel(QObject* parent)
{
    //TEST CODE
    QList<QVariant> list;
    list.append("RootCol1");
    list.append("RootCol2");
    m_rootItem = new TreeViewItem(list,nullptr);

    AddTestData(m_rootItem,"./");
}

int TreeViewModel::columnCount(const QModelIndex &parent) const
{
    return m_rootItem->columnCount();
}

/*
 * Returns the index of the item in the model specified by the given row, column and parent index.
 * When reimplementing this function in a subclass, call createIndex() to generate model indexes that other components can use to refer to items in your model.
*/
QModelIndex TreeViewModel::index(int row, int column, const QModelIndex &parent) const
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

QVariant TreeViewModel::data(const QModelIndex &index, int role) const
{
    TreeViewItem* item = static_cast<TreeViewItem*>(index.internalPointer());

    if(!item)
        return "Error";

    switch (role) {
    case ItemRoles::MROLE_Name:
        return item->data(0);
        break;
    case ItemRoles::MROLE_CreateDate:
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
QModelIndex TreeViewModel::parent(const QModelIndex &child) const
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

int TreeViewModel::rowCount(const QModelIndex &parent) const
{
    if(!parent.isValid())
        return m_rootItem->childCount();

    TreeViewItem* parentItem = static_cast<TreeViewItem*>(parent.internalPointer());
    if(!parentItem)
        return 0;

    return parentItem->childCount();
}

QHash<int, QByteArray> TreeViewModel::roleNames() const
{
    QHash<int, QByteArray> names(QAbstractItemModel::roleNames());
    names[ItemRoles::MROLE_Name] = "Name";
    names[ItemRoles::MROLE_CreateDate] = "CreateDate";

    return names;
}

void TreeViewModel::AddTestData(TreeViewItem* item, const QString path)
{
    QDir local_dir(path);
    local_dir.setFilter(QDir::Dirs | QDir::Files);
    local_dir.setSorting(QDir::DirsFirst);
    QFileInfoList lst =local_dir.entryInfoList();
    for(auto info : lst){
        if(info.fileName() == "."  || info.fileName() == "..")
            continue;
        QList<QVariant> infos;
        infos.append(info.fileName());
        infos.append(info.created().toString());

        TreeViewItem* subItem = new TreeViewItem(infos,item);
        item->appendChild(subItem);

        if(info.isDir())
        {
            AddTestData(subItem,info.filePath());
        }
    }
}

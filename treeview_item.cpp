#include "treeview_item.h"

TreeViewItem::TreeViewItem()
    :m_parentItem(nullptr)
{
}

TreeViewItem::TreeViewItem(const QList<QVariant> &data, TreeViewItem *parent)
{
    m_parentItem = parent;
    m_data = data;
}

TreeViewItem::~TreeViewItem()
{
    qDeleteAll(m_childItems);
}

void TreeViewItem::appendChild(TreeViewItem *item)
{
    m_childItems.append(item);
}

void TreeViewItem::clearAllChild()
{
    //TODO
}

TreeViewItem *TreeViewItem::child(int row)
{
    return m_childItems.value(row);
}

int TreeViewItem::childCount() const
{
    return m_childItems.count();
}

int TreeViewItem::columnCount() const
{
    return m_data.count();
}

QVariant TreeViewItem::data(int column) const
{
    return m_data.value(column);
}

TreeViewItem* TreeViewItem::parent() const
{
    return m_parentItem;
}

int TreeViewItem::row() const
{
    if(!m_parentItem)
        return 0;

    return m_parentItem->m_childItems.indexOf(const_cast<TreeViewItem*>(this));
}

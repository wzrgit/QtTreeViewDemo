#ifndef TREEVIEW_ITEM_H
#define TREEVIEW_ITEM_H

#include <QAbstractItemModel>

class TreeViewItem
{
public:
    TreeViewItem();
    TreeViewItem(const QList<QVariant>& data, TreeViewItem* parent);
    ~TreeViewItem();

    void appendChild(TreeViewItem* item);
    void clearAllChild();

    TreeViewItem* child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    TreeViewItem* parent() const;
    int row() const;

private:
    TreeViewItem* m_parentItem;
    QList<TreeViewItem*> m_childItems;
    QList<QVariant> m_data;
};

#endif //TREEVIEW_ITEM_H

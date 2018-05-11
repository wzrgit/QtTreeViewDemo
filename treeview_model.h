#ifndef TREEVIEW_FILESYSTEM_MODEL_H
#define TREEVIEW_FILESYSTEM_MODEL_H

#include <QAbstractItemModel>
#include "treeview_item.h"

class TreeViewModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    enum ItemRoles{
        MROLE_Name=Qt::UserRole + 1,
        MROLE_CreateDate
    };
    Q_ENUM(ItemRoles)
public:
    TreeViewModel(QObject *parent=nullptr);
    virtual int columnCount(const QModelIndex &parent) const override;
    virtual QModelIndex index(int row, int column, const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QModelIndex parent(const QModelIndex &child) const override;
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QHash<int,QByteArray> roleNames() const override;

    void AddTestData(TreeViewItem* item, const QString path);
private:
    TreeViewItem *m_rootItem;
};

#endif // TREEVIEW_FILESYSTEM_MODEL_H

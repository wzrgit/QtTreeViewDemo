import QtQuick 2.6
import QtQuick.Controls 1.4

Rectangle {
    property alias mouseArea: mouseArea
    property alias leftTreeView: leftTreeView
    property alias btnInsertRow: btnInsertRow
    property alias btnRemoveRow: btnRemoveRow

    width: 360
    height: 360

    MouseArea {
        id: mouseArea
        anchors.rightMargin: -310
        anchors.bottomMargin: -210
        anchors.fill: parent
    }
    Column {
        anchors.rightMargin: -310
        anchors.bottomMargin: -210
        anchors.fill: parent
        spacing: 2
        TreeView {
            id:leftTreeView
            width: 300
            height: parent.height
            TableViewColumn {
                title: "Name"
                role: "Name"
                width: 200
            }
            TableViewColumn {
                title: "Permissions"
                role: "CreateDate"
                width: 100
            }
            model: fileSystemModel
        }

        Rectangle{
            id:btnPanel
//            border.color: "red"
//            border.width: 1
            x:leftTreeView.x + leftTreeView.width + 5
//            Button {
//                id:btnLoadData
//                width: 75
//                height: 25
//                x:5
//                text:"ImportData"
//            }
            Button {
                id:btnInsertRow
                width:75
                height: 25
                x:5
                text: "InsertItem"
            }

            Button {
                id:btnRemoveRow
                width:btnInsertRow.width
                height: btnInsertRow.height
                x:btnInsertRow.x
                y:btnInsertRow.y + btnInsertRow.height + 5
                text:"RemoveItem"
            }
        }

    }


}

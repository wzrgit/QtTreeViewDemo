import QtQuick 2.6
import QtQuick.Controls 1.4

Rectangle {
    property alias mouseArea: mouseArea
    property alias leftTreeView: leftTreeView
    //    property alias btnInsertRow: btnInsertRow
    //    property alias btnRemoveRow: btnRemoveRow
    property alias textDesc: textDesc

    width: 600
    height: 600

    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }
    Column {
        anchors.fill: parent
        spacing: 2
        TreeView {
            id: leftTreeView
            width: 400
            height: parent.height
            TableViewColumn {
                title: "Name"
                role: "Name"
                width: 200
            }
            TableViewColumn {
                title: "CreateDate"
                role: "CreateDate"
                width: 200
            }
            model: itemModel
        }

        Rectangle {
            id: btnPanel
            anchors.left: leftTreeView.right
            anchors.top: parent.top
            anchors.right: parent.right
            x: leftTreeView.x + leftTreeView.width + 5

            //            Button {
            //                id:btnLoadData
            //                width: 75
            //                height: 25
            //                x:5
            //                text:"ImportData"
            //            }
            //            Button {
            //                id: btnInsertRow
            //                width: 75
            //                height: 25
            //                x: 15
            //                y: 15
            //                text: "InsertItem"
            //            }

            //            Button {
            //                id: btnRemoveRow
            //                width: btnInsertRow.width
            //                height: btnInsertRow.height
            //                x: btnInsertRow.x
            //                y: btnInsertRow.y + btnInsertRow.height + 5
            //                text: "RemoveItem"
            //            }
            Text {
                id: textDesc
                y: 340
                height: 260
                text: qsTr("Text")
                anchors.right: parent.right
                anchors.rightMargin: 0
                anchors.left: parent.left
                anchors.leftMargin: 5
                font.pixelSize: 12
            }
        }
    }
}

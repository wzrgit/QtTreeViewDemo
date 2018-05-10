import QtQuick 2.6
import QtQuick.Window 2.2
import m.fileSystemModel 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    FileSystemModel {
        id:fileSystemModel
    }

    MainForm {
        anchors.fill: parent
        mouseArea.onClicked: {            
        }

        btnInsertRow.onClicked: {
        }

        btnRemoveRow.onClicked: {
        }
    }
}

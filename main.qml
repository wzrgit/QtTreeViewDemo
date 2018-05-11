import QtQuick 2.6
import QtQuick.Window 2.2
import m.itemModel 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("TreeView Demo")

    TreeViewModel {
        id:itemModel
    }

    MainForm {
        anchors.fill: parent        
        mouseArea.onClicked: {            
        }

        function itemData(idx){
            return leftTreeView.model.data(idx, TreeViewModel.MROLE_Name) + " " + leftTreeView.model.data(idx,TreeViewModel.MROLE_CreateDate);
        }


        leftTreeView.onSelectionChanged: {
            console.log("Selected Changed")
        }

        leftTreeView.onCurrentIndexChanged: {
            console.log("CurrentIndexChanged, CurrentIndex:" + leftTreeView.model.data(leftTreeView.currentIndex,TreeViewModel.MROLE_Name))
            textDesc.text = itemData(leftTreeView.currentIndex)
        }

        leftTreeView.onClicked: {
//            console.log("OnClicked")
        }
    }
}

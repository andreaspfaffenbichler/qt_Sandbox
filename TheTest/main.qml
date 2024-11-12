import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs
import QtQuick.Layouts

Window {
    id: mainWindow
    visible: true
    height: 600
    width: 800

    ColumnLayout
    {
        anchors.fill: parent

        TreeView {
            Layout.preferredWidth: 500
            Layout.preferredHeight: 500
            model : test.getTreeModel()
            selectionModel: test.getSelectionModel()
            delegate: TreeViewDelegate {}
            onModelChanged: expandRecursively()
        }

        Button{
           text : "select all"
           onClicked: test.selectAll()
        }
        Button{
           text : "deselect 1"
           onClicked: test.deselectOne()
        }
    }
}

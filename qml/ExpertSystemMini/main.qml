import QtQuick 2.2
import QtQuick.Window 2.0
import QtQuick.Controls 1.1
import QtQuick.Dialogs 1.1
import QtQuick.Layouts 1.1
import "modules"
import "js/scripts.js" as JavaScript
import FileIO 1.0

ApplicationWindow {
    id: appWindow
    title: "Expert System Mini"
    visible: true

    width: 640
    height: 480
    minimumWidth: 640
    minimumHeight: 480

    menuBar: CustomMenuBar { }

    ColumnLayout {
        id: mainLayout
        anchors.fill: parent

        TextArea {
            id: informationTA
            readOnly: true
            implicitHeight: parent.height / 10
            Layout.fillWidth: true
            anchors.top: parent.top
        }

        ItemsNProcess {
                implicitHeight: (parent.height - informationTA.height) / 2
                Layout.fillWidth: true
                anchors.top: informationTA.bottom
        }

        Questions {
            implicitHeight: (parent.height - informationTA.height) / 2
            Layout.fillWidth: true
            anchors.bottom: parent.bottom
        }
    }

    FileIO {
        id: fileHandler
        onError: console.log(msg)
    }

    FileDialog {
        id: fileDialog
        nameFilters: [ "Mini knowledge base (*.mkb)" ]
        onAccepted: {
            fileHandler.source = fileUrl;
            fileHandler.setProperties();
        }
    }
    Action {
        id: openAction
        text: "&Open file"
        shortcut: StandardKey.Open
        onTriggered: fileDialog.open()
        tooltip: "Open an knowledge base"
    }
    Action {
        id: copyAction
        text: "&Copy"
        shortcut: StandardKey.Copy
        enabled: (!!activeFocusItem && !!activeFocusItem["copy"])
        onTriggered: activeFocusItem.copy()
    }
    Action {
        id: cutAction
        text: "&Cut"
        shortcut: StandardKey.Cut
        enabled: (!!activeFocusItem && !!activeFocusItem["cut"])
        onTriggered: activeFocusItem.cut()
    }
    Action {
        id: pasteAction
        text: "&Paste"
        shortcut: StandardKey.Paste
        enabled: (!!activeFocusItem && !!activeFocusItem["paste"])
        onTriggered: activeFocusItem.paste()
    }
    Action {
        id: aboutAction
        text: "&About"
        shortcut: "F1"
        //onTriggered: aboutDialog.open()
    }
    Action {
        id: changeSettings
        text: "&Change"
        //onTriggered: activeFocusItem.copy()
    }
    Action {
        id: resetToDefault
        text: "&Reset"
        //onTriggered: activeFocusItem.cut()
    }
    Action {
        id: startConsultation
        text: "&Start consultation"
        shortcut: "F8"
        //onTriggered: activeFocusItem.paste()
    }
    Action {
        id: cancelSelectedAnswers
        text: "&Cancel Selected Answers"
        shortcut: "F9"
        //onTriggered: aboutDialog.open()
    }
}

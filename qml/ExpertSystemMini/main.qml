import QtQuick 2.2
import QtQuick.Window 2.0
import QtQuick.Controls 1.1
import QtQuick.Dialogs 1.1
import QtQuick.Layouts 1.1
import "modules"
import "js/scripts.js" as JavaScript
import ExpertSystem 1.0

ApplicationWindow {
    id: appWindow
    title: "Expert System Mini"
    visible: true

    width: 640
    height: 480
    minimumWidth: 640
    minimumHeight: 480

    menuBar: CustomMenuBar {
        id: customMenu
    }

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
            id: itemsNProcessObject
            implicitHeight: (parent.height - informationTA.height) / 2
            Layout.fillWidth: true
            anchors.top: informationTA.bottom
        }

        Questions {
            id: questionTables
            implicitHeight: (parent.height - informationTA.height) / 2
            Layout.fillWidth: true
            anchors.bottom: parent.bottom
        }
    }

    ExpertSystem {
        id: expertSystem
        onQuestionChoosed: {
            itemsNProcessObject.setCurrentQuestion(expertSystem.getCurrentQuestion());
            updateQuestionModels();
        }

    }

    FileDialog {
        id: fileDialog
        nameFilters: [ "Mini knowledge base (*.mkb)" ]
        onAccepted: {
            expertSystem.setSource(fileUrl);
            updateQuestionModels();

            informationTA.text = expertSystem.getDescription();
            startConsultation.enabled = !startConsultation.enabled;
            questionTables.toggleButtons();
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
        id: aboutAction
        text: "&About"
        shortcut: "F1"
        //onTriggered: aboutDialog.open()
    }
    Action {
        id: startConsultation
        text: "&Start consultation"
        shortcut: "F8"
        enabled: false
        onTriggered: {
            itemsNProcessObject.enableInput();
            customMenu.toggleActionInConsultation();
            expertSystem.beginConsultation();
        }
    }
    Action {
        id: cancelLastAnswer
        text: "&Cancel last answer"
        enabled: false
        shortcut: "F9"
        //onTriggered: aboutDialog.open()
    }
    Action {
        id: stopConsultation
        text: "&Stop consultation"
        shortcut: "F8"
        //onTriggered: aboutDialog.open()
    }

    ListModel {
        id: itemsModel
    }

    ListModel {
        id: activeQuestionsModel
    }

    ListModel {
        id: inactiveQuestionsModel
    }

    function getActiveQuestionsModel() {
        var i = 0;

        activeQuestionsModel.clear();
        var count = expertSystem.getActiveQuestionsNumber();

        if (count >= 1) {
            for (; i < count; i++) {
                activeQuestionsModel.append({"Question" : expertSystem.getActiveQuestion(i)});
            }
        }
    }

    function getInactiveQuestionsModel() {
        var i = 0;

        inactiveQuestionsModel.clear();
        var count = expertSystem.getInactiveQuestionsNumber();

        if (count >= 1) {
            for (; i < count; i++) {
                inactiveQuestionsModel.append({"Question" : expertSystem.getInactiveQuestion(i)});
            }
        }
    }

    function getItemsModel() {
        var i = 0;

        itemsModel.clear();

        for (; i < expertSystem.getItemsNumber(); i++) {
            itemsModel.append({"Possibility" : expertSystem.getItemPossibility(i),
                                  "Item" : expertSystem.getItemName(i)});
        }
    }

    function updateQuestionModels() {
        getItemsModel();
        getActiveQuestionsModel();
        getInactiveQuestionsModel();
        itemsNProcessObject.setItemsModel(itemsModel);
        questionTables.setActiveQuestionsModel(activeQuestionsModel);
        questionTables.setInactiveQuestionsModel(inactiveQuestionsModel);
    }

    function fromActiveToInactive(index) {
        expertSystem.fromActiveToInactive(index);
        updateQuestionModels();
    }

    function fromInactiveToActive(index) {
        expertSystem.fromInactiveToActive(index);
        updateQuestionModels();
    }
}

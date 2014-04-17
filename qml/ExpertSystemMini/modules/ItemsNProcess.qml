import QtQuick 2.2
import QtQuick.Controls 1.1
//import QtQuick.Controls.Styles 1.1
import QtQuick.Layouts 1.1

Item {
    function setItemsModel(model) {
        itemsTable.model = model;
    }

    function enableInput(){
        inputSubmit.enabled = true;
    }

    function setCurrentQuestion(question) {
        currentQuestionTA.text = question;
    }

    property string stateOfInputP: "P";
    property string stateOfInputCC: "CC"

    property string inputTypeText1:
        "Enter confidence coefficient on the scale: -5(No) .. 0(Dont know) .. 5(Yes)";
    property string inputTypeText2:
        "Enter possibility of truth of statement (number between 0 and 1)";

    RowLayout {
        anchors.fill: parent

        GroupBox {
            id: itemsGB
            implicitWidth: parent.width * 0.35
            implicitHeight: parent.height
            anchors.left: parent.left

            TableView {
                id: itemsTable
                anchors.top: parent.top
                anchors.fill: parent
                Layout.fillWidth: true
                //sortIndicatorVisible: true
                //onSortIndicatorColumnChanged: model.sort(sortIndicatorColumn, sortIndicatorOrder)
                //onSortIndicatorOrderChanged: model.sort(sortIndicatorColumn, sortIndicatorOrder)

                TableViewColumn {
                    role: "Possibility"
                    title: "Possibility"
                    width: itemsGB.width * 0.20
                }
                TableViewColumn {
                    role: "Item"
                    title: "Item"
                    width: itemsGB.width * 0.70
                }
            }
        }

        GroupBox {
            id: questionGB
            implicitWidth: parent.width - itemsGB.width
            implicitHeight: parent.height
            anchors.right: parent.right

            ColumnLayout {
                anchors.fill: parent

                TableView {
                    id: questionTable
                    anchors.top: parent.top
                    Layout.fillHeight: true
                    implicitWidth: parent.width
                    //sortIndicatorVisible: true
                    //onSortIndicatorColumnChanged: model.sort(sortIndicatorColumn, sortIndicatorOrder)
                    //onSortIndicatorOrderChanged: model.sort(sortIndicatorColumn, sortIndicatorOrder)

                    TableViewColumn {
                        role: "Number"
                        title: "Number"
                        width: questionGB.width * 0.13
                    }
                    TableViewColumn {
                        role: "Confidence"
                        title: "Confidence"
                        width: questionGB.width * 0.17
                    }
                    TableViewColumn {
                        role: "Question"
                        title: "Question"
                        width: questionGB.width * 0.65
                    }
                }

                TextArea {
                    id: currentQuestionTA
                    readOnly: true
                    implicitWidth: parent.width
                    implicitHeight: parent.height / 5
                    anchors.top: questionTable.bottom
                    anchors.topMargin: 3
                }

                RowLayout {
                    implicitWidth: parent.width
                    Layout.fillHeight: true
                    anchors.top: currentQuestionTA.bottom
                    anchors.topMargin: 3

                    Button {
                        id: inputTypeToggle
                        text: stateOfInputCC + "\\" + stateOfInputP
                        state: stateOfInputCC
                        states: [
                            State {
                                name: stateOfInputCC
                                PropertyChanges {
                                    target: inputInformationField
                                    text: inputTypeText1
                                }
                            },
                            State {
                                name: stateOfInputP
                                PropertyChanges {
                                    target: inputInformationField
                                    text: inputTypeText2
                                }
                            }
                        ]
                        onClicked: {
                            if (inputTypeToggle.state == stateOfInputCC) {
                                inputTypeToggle.state = stateOfInputP
                            } else {
                                inputTypeToggle.state = stateOfInputCC
                            }
                        }
                    }
                    TextField {
                        id: inputInformationField
                        readOnly: true
                        anchors.left: inputTypeToggle.right
                        anchors.leftMargin: 2
                        Layout.fillWidth: true
                        font.family: "Arial"
                        font.pointSize: 8
                        anchors.right: inputValueField.left
                        anchors.rightMargin: 2
                    }
                    TextField {
                        id: inputValueField
                        anchors.right: inputSubmit.left
                        anchors.rightMargin: 2
                        implicitWidth: questionGB.implicitWidth / 10
                    }
                    Button {
                        id: inputSubmit
                        enabled: false
                        anchors.right: parent.right
                        anchors.rightMargin: 2
                        text: "OK"
                        onClicked: {
                            cancelLastAnswer.enabled = !cancelLastAnswer.enabled;
                        }
                    }
                }
            }
        }
    }
}



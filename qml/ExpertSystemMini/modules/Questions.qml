import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.1

Item {
    id: questionsItem
    property int imageWidth: 40

    function setActiveQuestionsModel(model) {
        activeQuestions.setTableModel(model);
    }

    function setInactiveQuestionsModel(model) {
        inactiveQuestions.setTableModel(model);
    }

    function toggleButtons() {
        inactiveToActive.enabled = !inactiveToActive.enabled;
        activeToInactive.enabled = !activeToInactive.enabled;
    }

    RowLayout {
        id: questionsManager
        anchors.fill: parent

        QuestionTable {
            id: activeQuestions
            anchors.left: parent.left
            anchors.right: questionControlPanel.left
        }

        GroupBox {
            id: questionControlPanel
            implicitWidth: 100
            implicitHeight: parent.height
            anchors.centerIn: parent

            ColumnLayout {
                anchors.fill: parent

                Text {
                    id: activeLabel
                    anchors.top: parent.top
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: "Questions control"
                }
                Button {
                    id: selectAllButton
                    text: "Select all"
                    onClicked: selectAllQuestions.trigger()
                    Layout.fillWidth: true
                }
                RowLayout {
                    anchors.top: selectAllButton.bottom
                    implicitWidth: parent.width

                    Button {
                        id: inactiveToActive
                        anchors.left: parent.left
                        style: ButtonStyle {
                            background: BorderImage {
                                source: "../images/previous.png"
                            }
                        }
                        enabled: false
                        implicitWidth: imageWidth
                        implicitHeight: implicitWidth
                        onClicked: {
                            if (inactiveQuestions.getFocusItemIndex() !== -1) {
                                fromInactiveToActive(inactiveQuestions.getFocusItemIndex());
                            }
                        }
                    }

                    Button {
                        id: activeToInactive
                        anchors.right: parent.right
                        style: ButtonStyle {
                            background: BorderImage {
                                source: "../images/next.png"
                            }
                        }
                        enabled: false
                        implicitWidth: imageWidth
                        implicitHeight: implicitWidth
                        onClicked: {
                            if (activeQuestions.getFocusItemIndex() !== -1) {
                                fromActiveToInactive(activeQuestions.getFocusItemIndex());
                            }
                        }
                    }
                }
            }
        }

        QuestionTable {
            id: inactiveQuestions
            anchors.left: questionControlPanel.right
            anchors.right: parent.right
        }
    }

    Action {
        id: selectAllQuestions
        text: "&Select all"
        shortcut: StandardKey.SelectAll
        //onTriggered: activeFocusItem.selectAll()
        //enabled: (!!activeFocusItem && !!activeFocusItem["selectAll"])
    }
}

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

    RowLayout {
        id: questionsManager
        anchors.fill: parent

        QuestionTable {
            id: activeQuestions
            anchors.left: parent.left
            anchors.right: questionControlPanel.left
        }

        /*TableView {
            //model: dummyModel
            id: activeQuestions
            anchors.top: parent.top
            //anchors.fill: parent
            Layout.fillWidth: true
            //sortIndicatorVisible: true
            //onSortIndicatorColumnChanged: model.sort(sortIndicatorColumn, sortIndicatorOrder)
            //onSortIndicatorOrderChanged: model.sort(sortIndicatorColumn, sortIndicatorOrder)

            TableViewColumn {
                role: "Significance"
                title: "Significance"
                width: activeQuestions.width * 0.25
            }
            TableViewColumn {
                role: "Question"
                title: "Question"
                width: activeQuestions.width * 0.70
            }
        }*/

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
                        anchors.left: parent.left
                        style: ButtonStyle {
                            background: BorderImage {
                                source: "../images/previous.png"
                            }
                        }
                        implicitWidth: imageWidth
                        implicitHeight: implicitWidth
                        //onClicked:
                    }

                    Button {
                        anchors.right: parent.right
                        style: ButtonStyle {
                            background: BorderImage {
                                source: "../images/next.png"
                            }
                        }
                        implicitWidth: imageWidth
                        implicitHeight: implicitWidth
                        onClicked: //fromActiveToInactive(activeQuestions.)
                        {
                            activeQuestions.getFocusItemIndex();
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
        onTriggered: activeFocusItem.selectAll()
        enabled: (!!activeFocusItem && !!activeFocusItem["selectAll"])
    }
}

import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.1

MenuBar {
            id: customMenuBar

            function toggleActionInConsultation(){
                if (consultationFlag) {
                    consultationButton.action = stopConsultation;
                    consultationFlag = false;
                } else {
                    consultationButton.action = startConsultation;
                    consultationFlag = true;
                }
            }
            property bool consultationFlag: true

            Menu {
                title: "&File"
                MenuItem {
                    action: openAction
                }
                MenuItem {
                    text: "Close"
                    shortcut: StandardKey.Quit
                    onTriggered: Qt.quit()
                }
            }
            Menu {
                title: "&Consultation"
                MenuItem {
                    id: consultationButton
                    enabled: false
                    action: startConsultation
                }
                MenuItem {
                    id: cancelButton
                    action: cancelLastAnswer
                }
            }
            Menu {
                title: "&Help"
                MenuItem {
                    action: aboutAction
                }
            }
        }

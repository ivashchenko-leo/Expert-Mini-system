import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.1

MenuBar {
            id: customMenuBar

            function toggleActionInConsultation(){
                if (!consultationButton.checked) {
                    consultationButton.action = stopConsultation;
                    consultationButton.checked = true;
                } else {
                    consultationButton.action = startConsultation;
                    consultationButton.checked = false;
                }
            }

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
                    checked: false
                    action: startConsultation
                }
                MenuItem {
                    id: cancelButton
                    action: cancelLastAnswer
                    enabled: false
                }
            }
            Menu {
                title: "&Help"
                MenuItem {
                    action: aboutAction
                }
            }
        }

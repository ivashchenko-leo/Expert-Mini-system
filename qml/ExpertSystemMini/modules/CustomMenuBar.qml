import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.1

MenuBar {
            id: customMenuBar

            function toggleActionInConsultation(){
                consultationButton.checked = !consultationButton.checked;
                consultationButton.action = stopConsultation;
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
                    checked: false
                    action: startConsultation
                }
                MenuItem {
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

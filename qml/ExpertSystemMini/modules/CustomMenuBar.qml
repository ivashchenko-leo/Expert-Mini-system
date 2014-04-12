import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.1

MenuBar {
              id: customMenuBar

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
                  title: "&Settings"
                  MenuItem {
                      action: changeSettings
                  }
                  MenuSeparator {}
                  MenuItem {
                      action: resetToDefault
                  }
              }
              Menu {
                  title: "&Consultation"
                  MenuItem {
                      action: startConsultation
                  }
                  MenuItem {
                      action: cancelSelectedAnswers
                  }
              }
              Menu {
                  title: "&Help"
                  MenuItem {
                      action: aboutAction
                  }
              }
          }

import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1

Item {
    anchors.top: parent.top
    anchors.bottom: parent.bottom
    Layout.fillHeight: true
    anchors.margins: 5

    function setTableModel(model) {
        someTableView.model = model;
    }

    function getFocusItemIndex() {
        return someTableView.currentRow;
    }

    function getTableFocus() {
        return someTableView.activeFocus;
    }


    TableView {
        id: someTableView
        anchors.fill: parent
        //sortIndicatorVisible: true
        //onSortIndicatorColumnChanged: model.sort(sortIndicatorColumn, sortIndicatorOrder)
        //onSortIndicatorOrderChanged: model.sort(sortIndicatorColumn, sortIndicatorOrder)

        TableViewColumn {
            role: "Question"
            title: "Question"
            width: someTableView.width * 0.68
        }
    }
}



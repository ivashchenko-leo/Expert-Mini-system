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

    TableView {
        id: someTableView
        //model: dummyModel
        anchors.fill: parent
        //sortIndicatorVisible: true
        //onSortIndicatorColumnChanged: model.sort(sortIndicatorColumn, sortIndicatorOrder)
        //onSortIndicatorOrderChanged: model.sort(sortIndicatorColumn, sortIndicatorOrder)

        TableViewColumn {
            role: "Significance"
            title: "Significance"
            width: someTableView.width * 0.31
        }
        TableViewColumn {
            role: "Question"
            title: "Question"
            width: someTableView.width * 0.68
        }
    }
}



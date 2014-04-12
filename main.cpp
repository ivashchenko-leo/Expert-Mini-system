/*#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QtQuick2ApplicationViewer viewer;
    viewer.setMainQmlFile(QStringLiteral("qml/ExpertSystemMini/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
*/
#include <QtGui/QGuiApplication>
#include <QtQml>
#include <fileio.h>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    qmlRegisterType<FileIO, 1>("FileIO", 1, 0, "FileIO");

    QQmlApplicationEngine engine;
    engine.load(QUrl("qml/ExpertSystemMini/main.qml"));

    return app.exec();
}

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
#include "expertsystem.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    qmlRegisterType<ExpertSystem, 1>("ExpertSystem", 1, 0, "ExpertSystem");

    QQmlApplicationEngine engine;
    engine.load(QUrl("qml/ExpertSystemMini/main.qml"));

    return app.exec();
}

# Add more folders to ship with the application, here
folder_01.source = qml/ExpertSystemMini
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    fileio.cpp \
    item.cpp \
    datamanager.cpp

# Installation path
# target.path =

# Please do not modify the following two lines. Required for deployment.
include(qtquick2applicationviewer/qtquick2applicationviewer.pri)
qtcAddDeployment()

OTHER_FILES += \
    qml/ExpertSystemMini/modules/CustomMenuBar.qml \
    qml/ExpertSystemMini/modules/ItemsNProcess.qml \
    qml/ExpertSystemMini/modules/Questions.qml \
    qml/ExpertSystemMini/modules/QuestionTable.qml \
    qml/ExpertSystemMini/js/scripts.js

RESOURCES +=

HEADERS += \
    fileio.h \
    item.h \
    datamanager.h

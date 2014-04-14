#ifndef DATAMANAGER_H
#define DATAMANAGER_H
#include "fileio.h"
#include <QObject>

class DataManager : public QObject
{
    Q_OBJECT
public:

    explicit DataManager(QObject *parent = 0);
    Q_INVOKABLE QString getQuestion(const int& index);
    Q_INVOKABLE QString getSignificance(const int& index);
    Q_INVOKABLE QString getItemName(const int& index);
    Q_INVOKABLE QString getItemPossibility(const int& index);
    Q_INVOKABLE QString getDescription() { return pFile.getDescription(); }
    Q_INVOKABLE int getQuestionsNumber() { return pFile.getQuestionsNumber(); }
    Q_INVOKABLE int getItemsNumber() { return pFile.getItemsNumber(); }
    Q_INVOKABLE void setSource(const QString& source);
signals:

private:
    FileIO pFile;

};

#endif // DATAMANAGER_H

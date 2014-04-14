#include "datamanager.h"

DataManager::DataManager(QObject *parent) :
    QObject(parent)
{
}

QString DataManager::getQuestion(const int& index)
{
    return pFile.getQuestions().at(index);
}

QString DataManager::getSignificance(const int& index)
{
    return "1";
}

QString DataManager::getItemName(const int& index)
{
    return pFile.getItems().at(index)->getName();
}

QString DataManager::getItemPossibility(const int& index)
{
    QString str;
    return str.setNum(pFile.getItems().at(index)->getPossibility());
}
void DataManager::setSource(const QString& source)
{
    pFile.setSource(source);
    pFile.setProperties();
}

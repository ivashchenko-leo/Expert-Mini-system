#include "expertsystem.h"

ExpertSystem::ExpertSystem(QObject *parent) :
    QObject(parent),
    pCurrentState(new ModelState(this))
{
}

void ExpertSystem::start()
{
    pCurrentState->setItems(pFile.getItems());
    pCurrentState->setNumber(0);
    pCurrentState->setActiveQuestions(pFile.getQuestions());
}

void ExpertSystem::beginConsultation()
{

}

void ExpertSystem::fromActiveToInactive(int index)
{
    pCurrentState->getInactiveQuestions().append(pCurrentState->getActiveQuestions().at(index));
    qDebug() << pCurrentState->getActiveQuestions().at(index);
    pCurrentState->getActiveQuestions().removeAt(index);
    qDebug() << pCurrentState->getActiveQuestions().at(index);
}

void ExpertSystem::fromInactiveToActive(int index)
{

}

QString ExpertSystem::getActiveQuestion(const int& index)
{
    return pCurrentState->getActiveQuestions().at(index);
}

QString ExpertSystem::getInactiveQuestion(const int& index)
{
    return pCurrentState->getInactiveQuestions().at(index);
}

QString ExpertSystem::getItemName(const int& index)
{
    return pCurrentState->getItems().at(index)->getName();
}

QString ExpertSystem::getItemPossibility(const int& index)
{
    QString str;
    return str.setNum(pCurrentState->getItems().at(index)->getPossibility());
}
void ExpertSystem::setSource(const QString& source)
{
    pFile.setSource(source);
    pFile.setProperties();
    start();
}

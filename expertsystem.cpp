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
    getNewQuestion();
}

void ExpertSystem::fromActiveToInactive(const int& index)
{
    pCurrentState->getInactiveQuestions().append(pCurrentState->getActiveQuestions().at(index));
    pCurrentState->getActiveQuestions().removeAt(index);
}

void ExpertSystem::fromInactiveToActive(const int& index)
{
    pCurrentState->getActiveQuestions().append(pCurrentState->getInactiveQuestions().at(index));
    pCurrentState->getInactiveQuestions().removeAt(index);
}

QString ExpertSystem::getActiveQuestion(const int& index)
{
    return pCurrentState->getActiveQuestions().at(index)->getString();
}

QString ExpertSystem::getInactiveQuestion(const int& index)
{
    return pCurrentState->getInactiveQuestions().at(index)->getString();
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

void ExpertSystem::setConfidence(QString confidence)
{
    pCurrentState->setConfidence(confidence.toDouble());
}

void ExpertSystem::calcNewPossibilities()
{

}

const Question* ExpertSystem::getNewQuestion()
{
    qsrand(QDateTime::currentMSecsSinceEpoch());

    int number = qrand() % (pCurrentState->getActiveQuestions().count());

    pCurrentState->setQuestion(pCurrentState->getActiveQuestions().at(number));
    pCurrentState->getActiveQuestions().removeAt(number);
    emit questionChoosed(number);

    return pCurrentState->getQuestion();
}



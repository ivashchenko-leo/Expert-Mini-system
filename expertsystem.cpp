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
    double Py, P, Pn, possibility;
    int i = 0;

    saveLastPossibilities();

    foreach (Item* item, pCurrentState->getItems()) {
        Py = item->getAnswersPossibility().at(pCurrentState->getQuestion()->getNumber());
        P = item->getPossibility();
        Pn = item->getNotAnswersPossibility().at(pCurrentState->getQuestion()->getNumber());

        if (pCurrentState->getConfidence() >= 0.5) {
            if (pCurrentState->getConfidence() == 0.5) {
                possibility = P;
                break;
            }
            possibility = Py * P / (Py * P + Pn * (1.0 - P));
        } else {
            possibility = 1.0 - ((1.0 - Py) * P / ((1.0 - Py) * P + (1.0 - Pn) * (1.0 - P)));
        }

        if (possibility <= 0.0) {
           possibility = 0.0;
        }
        if (possibility >= 1.0) {
           possibility = 1.0;
        }
        //possibility = possibility * pCurrentState->getConfidence();
        pCurrentState->getItems().at(i)->setPossibility(possibility);
        i++;
    }

    createNewState();
    checkIfItsEnd();
}

void ExpertSystem::saveLastPossibilities()
{
    QVector<double> pos;

    foreach (Item* item, pCurrentState->getItems()) {
        pos.append(item->getPossibility());
    }

    pItemsPos.push(pos);
}

void ExpertSystem::cancelLastState()
{
    if (stackOfStates.count() <= 1) {
        stopConsultation();
        getNewQuestion();
    } else {
        pCurrentState = stackOfStates.pop();
        pCurrentState->mergeItemsPos(pItemsPos.pop());
    }
}

void ExpertSystem::checkIfItsEnd()
{
    if (pCurrentState->getActiveQuestions().size() == 0 || pCurrentState->itemWithOnePExist()) {
        emit endConsultation();
    } else {
        getNewQuestion();
    }
}

void ExpertSystem::stopConsultation()
{
    stackOfStates.clear();
    delete pCurrentState;
    pCurrentState = new ModelState(this);
    setSource(pFile.source());
}

void ExpertSystem::createNewState()
{
    stackOfStates.push(pCurrentState);
    ModelState* newState = new ModelState(this);
    newState->setItems(pCurrentState->getItems());
    newState->setNumber(pCurrentState->getNumber() + 1);
    newState->setActiveQuestions(pCurrentState->getActiveQuestions());
    newState->setInactiveQuestions(pCurrentState->getInactiveQuestions());
    pCurrentState = newState;
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



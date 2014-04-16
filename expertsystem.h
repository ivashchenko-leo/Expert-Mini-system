#ifndef EXPERTSYSTEM_H
#define EXPERTSYSTEM_H
#include "modelstate.h"
#include "fileio.h"
//#include "item.h"
#include <QObject>

class ExpertSystem : public QObject
{
    Q_OBJECT
public:
    explicit ExpertSystem(QObject *parent = 0);
    Q_INVOKABLE void fromInactiveToActive(int index);
    //Q_INVOKABLE void cancelLastState();
    //Q_INVOKABLE void setNewState(double statement);
    Q_INVOKABLE void fromActiveToInactive(int index);
    Q_INVOKABLE void beginConsultation();

    Q_INVOKABLE QString getActiveQuestion(const int& index);
    Q_INVOKABLE QString getInactiveQuestion(const int& index);
    Q_INVOKABLE QString getItemName(const int& index);
    Q_INVOKABLE QString getItemPossibility(const int& index);
    Q_INVOKABLE QString getDescription() { return pFile.getDescription(); }
    Q_INVOKABLE int getActiveQuestionsNumber() { return pCurrentState->getActiveQuestions().count(); }
    Q_INVOKABLE int getInactiveQuestionsNumber() { return pCurrentState->getInactiveQuestions().count(); }
    Q_INVOKABLE int getItemsNumber() { return pCurrentState->getItems().count(); }
    Q_INVOKABLE void setSource(const QString& source);
signals:

private:
    FileIO pFile;
    void start();
    //const QString& getNewQuestion();
    //void calcItemsPossibilities();
    //const ModelState& getFirstState();
    ModelState* pCurrentState;
    //QStack<ModelState* > stackOfStates;
};

#endif // EXPERTSYSTEM_H

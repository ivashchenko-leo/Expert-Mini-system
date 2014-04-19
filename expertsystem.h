#ifndef EXPERTSYSTEM_H
#define EXPERTSYSTEM_H
#include "modelstate.h"
#include "fileio.h"
#include <QDateTime>
#include <QStack>

class ExpertSystem : public QObject
{
    Q_OBJECT
public:
    explicit ExpertSystem(QObject *parent = 0);
    Q_INVOKABLE void fromInactiveToActive(const int &index);
    Q_INVOKABLE void cancelLastState();
    Q_INVOKABLE void fromActiveToInactive(const int &index);
    Q_INVOKABLE void beginConsultation();

    Q_INVOKABLE QString getActiveQuestion(const int& index);
    Q_INVOKABLE QString getInactiveQuestion(const int& index);
    Q_INVOKABLE QString getItemName(const int& index);
    Q_INVOKABLE QString getItemPossibility(const int& index);
    Q_INVOKABLE QString getDescription() { return pFile.getDescription(); }
    Q_INVOKABLE int getActiveQuestionsNumber() { return pCurrentState->getActiveQuestions().count(); }
    Q_INVOKABLE int getInactiveQuestionsNumber() { return pCurrentState->getInactiveQuestions().count(); }
    Q_INVOKABLE int getItemsNumber() { return pCurrentState->getItems().count(); }
    Q_INVOKABLE QString getCurrentQuestion() { return pCurrentState->getQuestion()->getString(); }
    Q_INVOKABLE void setSource(const QString& source);
    Q_INVOKABLE void setConfidence(QString confidence);
    Q_INVOKABLE void calcNewPossibilities();
    Q_INVOKABLE void stopConsultation();
signals:
    void questionChoosed(const int& number);
    void endConsultation();

private:
    FileIO pFile;
    void start();
    void createNewState();
    void checkIfItsEnd();
    const Question *getNewQuestion();
    void saveLastPossibilities();
    QStack<QVector<double> > pItemsPos;
    ModelState* pCurrentState;
    QStack<ModelState* > stackOfStates;
};

#endif // EXPERTSYSTEM_H

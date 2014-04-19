#ifndef MODELSTATE_H
#define MODELSTATE_H
#include "item.h"
#include "question.h"
#include <QDebug>
#include <QObject>

class ModelState : public QObject
{
    Q_OBJECT
public:
    explicit ModelState(QObject *parent = 0);
    Question* getQuestion() { return pQuestion; }
    int& getNumber() { return pNumber; }
    double& getConfidence() { return pConfidence; }
    QList<Item* >& getItems() { return pItems; }
    QList<Question* >& getActiveQuestions() { return pActiveQuestions; }
    QList<Question* >& getInactiveQuestions() { return pInactiveQuestions; }
    void setNumber(const int& number) { pNumber = number; }
    void setQuestion(Question* question) { pQuestion = question; }
    void setConfidence(const double& confidence) { pConfidence = confidence; }
    void setItems(const QList<Item* >& items) { pItems = items; }
    void setActiveQuestions(const QList<Question* >& questions) { pActiveQuestions = questions; }
    void setInactiveQuestions(const QList<Question* >& questions) { pInactiveQuestions = questions; }
    void mergeItemsPos(const QVector<double>& pos);
    bool itemWithOnePExist();
signals:

private:
    int pNumber;
    Question* pQuestion;
    double pConfidence;
    QList<Item* > pItems;
    QList<Question* > pActiveQuestions;
    QList<Question* > pInactiveQuestions;
};

#endif // MODELSTATE_H

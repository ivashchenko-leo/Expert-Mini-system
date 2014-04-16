#ifndef MODELSTATE_H
#define MODELSTATE_H
#include "item.h"
#include <QObject>

class ModelState : public QObject
{
    Q_OBJECT
public:
    explicit ModelState(QObject *parent = 0);
    QString& getQuestion() { return pQuestion; }
    int& getNumber() { return pNumber; }
    double& getConfidence() { return pConfidence; }
    QList<Item* >& getItems() { return pItems; }
    QStringList& getActiveQuestions() { return pActiveQuestions; }
    QStringList& getInactiveQuestions() { return pInactiveQuestions; }
    void setNumber(const int& number) { pNumber = number; }
    void setQuestion(const QString& question) { pQuestion = question; }
    void setConfidence(const double& confidence) { pConfidence = confidence; }
    void setItems(const QList<Item* >& items) { pItems = items; }
    void setActiveQuestions(const QStringList& questions) { pActiveQuestions = questions; }
    void setInactiveQuestions(const QStringList& questions) { pInactiveQuestions = questions; }
signals:

private:
    int pNumber;
    QString pQuestion;
    double pConfidence;
    QList<Item* > pItems;
    QStringList pActiveQuestions;
    QStringList pInactiveQuestions;
};

#endif // MODELSTATE_H

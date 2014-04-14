#ifndef ITEM_H
#define ITEM_H
#include <QVector>
#include <QStringList>
#include <QObject>

class Item : public QObject
{
    Q_OBJECT
public:
    explicit Item(QObject *parent = 0);
    Item(QString item, const QString& separator = ",", QObject *parent = 0);
    void setName(const QString& name) { pName = name; }
    void setPossibility(const int& possibility) { pPossibility = possibility; }
    void setAnswersPossibility(const QVector<double> &answers);
    void setNotAnswersPossibility(const QVector<double> answers);

    const QString& getName() { return pName; }
    const double& getPossibility() { return pPossibility; }
    const QVector<double>& getAnswersPossibility() { return pAnswersIsTrue; }
    const QVector<double>& getNotAnswersPossibility() { return pNotAnswersButTrue; }
    const int& getQuestionsCounter() { return questionsCounter; }
signals:

private:
    QString pName;
    double pPossibility;
    QVector<double> pAnswersIsTrue;
    QVector<double> pNotAnswersButTrue;
    int questionsCounter;
};

#endif // ITEM_H

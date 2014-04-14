#include "item.h"

Item::Item(QObject *parent) :
    QObject(parent),
    questionsCounter(0)
{
}

Item::Item(QString item, const QString& separator, QObject *parent) :
    QObject(parent)
{
    QStringList itemByList = item.split(separator);

    pName = itemByList.at(0);
    pPossibility = itemByList.at(1).toDouble();

    for (int i = 2; i < itemByList.size(); i += 3) {
        pAnswersIsTrue.append(itemByList.at(i + 1).toDouble());
        pNotAnswersButTrue.append(itemByList.at(i + 2).toDouble());
    }

    questionsCounter = pAnswersIsTrue.size();
}

void Item::setNotAnswersPossibility(const QVector<double> answers)
{
    pNotAnswersButTrue = answers;
}

void Item::setAnswersPossibility(const QVector<double>& answers)
{
    //questionsCounter = answers.count();
    pAnswersIsTrue = answers;
}

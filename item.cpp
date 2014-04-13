#include "item.h"

Item::Item(QObject *parent) :
    QObject(parent),
    questionsCounter(0)
{
}

Item::Item(QString item, const QString& separator) :
    QObject()
{
    QStringList itemByList = item.split(separator);

    pName = itemByList.at(0);
    pPossibility = itemByList.at(1).toDouble();

    for (int i = 2; i < itemByList.size(); i += 3) {
        pAnswers.append(itemByList.at(i + 1).toInt());
        //pSomeShit.append(itemByList.at(i + 2).toDouble());
    }

    questionsCounter = pAnswers.size();
}

void Item::setAnswers(const QVector<int>& answers)
{
    questionsCounter = answers.count();
    pAnswers = answers;
}

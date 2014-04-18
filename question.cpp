#include "question.h"

Question::Question(QObject *parent) :
    QObject(parent)
{
}

Question::Question(const int& number, const QString& question, QObject *parent) :
    QObject(parent)
{
    setNumber(number);
    setString(question);
}

#ifndef QUESTION_H
#define QUESTION_H

#include <QObject>

class Question : public QObject
{
    Q_OBJECT
public:
    explicit Question(QObject* parent = 0);
    Question(const int& number, const QString& question, QObject *parent = 0);
    const QString& getString() { return pString; }
    const int& getNumber() { return pNumber; }
    void setString(const QString& question) { pString = question; }
    void setNumber(const int& number) { pNumber = number; }
signals:

private:
    QString pString;
    int pNumber;
};

#endif // QUESTION_H

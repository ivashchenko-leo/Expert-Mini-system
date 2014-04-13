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
    Item(QString item, const QString& separator = ",");
    void setName(const QString& name) { pName = name; }
    void setPossibility(const int& possibility) { pPossibility = possibility; }
    void setAnswers(const QVector<int>& answers);
    //void setSomeShit(const QVector<double> someShit) { pSomeShit = someShit; }

    const QString& getName() { return pName; }
    const double& getPossibility() { return pPossibility; }
    const QVector<int>& getAnswers() { return pAnswers; }
signals:

private:
    QString pName;
    double pPossibility;
    QVector<int> pAnswers;
    QVector<double> pSomeShit;
    int questionsCounter;
};

#endif // ITEM_H

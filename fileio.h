#ifndef FILEIO_H
#define FILEIO_H
#include <QFile>
#include <QTextStream>
#include <QObject>
#include <QDebug>
#include <QRegExp>
#include "item.h"

class FileIO : public QObject
{
    Q_OBJECT

public:
    Q_PROPERTY(QString source
               READ source
               WRITE setSource
               NOTIFY sourceChanged)
    Q_PROPERTY(QString description
               READ getDescription
               WRITE setDescription)
    Q_PROPERTY(QStringList questions
               READ getQuestions
               WRITE setQuestions)

    explicit FileIO(QObject *parent = 0);

    Q_INVOKABLE QString read();

    Q_INVOKABLE void setProperties();

    QString source() { return mSource; }
    QString getDescription() { return pDescription; }
    QStringList getQuestions() { return pQuestions; }
    QList<Item* > getItems() { return pItems; }
    int getQuestionsNumber() { return pQuestions.count(); }
    int getItemsNumber() { return pItems.count(); }

public slots:
    void setSource(const QString& source);
    void setDescription(const QString& description) { pDescription = description; }
    void setQuestions(const QString& questions);
    void setQuestions(const QStringList& questions);
    void setItems(const QList<Item* >& items) { pItems = items; }
    void setItems(const QString& items);
    void setItems(const QStringList& items);

signals:
    void sourceChanged(const QString& source);
    void error(const QString& msg);

private:
    const QString keyWordForItems;
    const QString keyWordForQuestions;
    QString parse(const QString regex, const bool isGreedy);
    bool write(const QString& data);

    QList<Item* > pItems;
    QStringList pQuestions;
    QString mSource;
    QString pDescription;
};

#endif // FILEIO_H

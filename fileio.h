#ifndef FILEIO_H
#define FILEIO_H
#include <QFile>
#include <QTextStream>
#include <QObject>
#include <QDebug>
#include <QRegExp>

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
               WRITE setDescription
               NOTIFY descriptionChanged)
    /*Q_PROPERTY(QString questions
               READ getQuestions
               WRITE setQuestions
               NOTIFY questionsChanged)*/

    explicit FileIO(QObject *parent = 0);

    Q_INVOKABLE QString read();

    Q_INVOKABLE void setProperties();

    QString source() { return mSource; }
    QString getDescription() { return pDescription; }
    //QString getQuestions() {}
public slots:
    void setSource(const QString& source);
    void setDescription(const QString& description) { pDescription = description; }

signals:
    void descriptionChanged(const QString& description);
    void sourceChanged(const QString& source);
    void error(const QString& msg);

private:
    QString parse(const QString regex, const bool isGreedy);
    bool write(const QString& data);

    //QString pQuestions;
    QString mSource;
    QString pDescription;
};

#endif // FILEIO_H

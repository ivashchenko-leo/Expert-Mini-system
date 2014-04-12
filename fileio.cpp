#include "fileio.h"

FileIO::FileIO(QObject *parent) :
    QObject(parent)
{
}

void FileIO::setSource(const QString& source)
{
    QString fixedSource = source;
    fixedSource.remove("file:///");
    mSource = fixedSource;
}

QString FileIO::read()
{
    if (mSource.isEmpty()){
        emit error("source is empty");
        return QString();
    }

    QFile file(mSource);
    QString fileContent;
    if ( file.open(QIODevice::ReadOnly) ) {
        QString line;
        QTextStream t( &file );
        do {
            line = t.readLine();
            fileContent += line + "\n";
         } while (!line.isNull());

        file.close();
    } else {
        emit error("Unable to open file");
        return QString();
    }
    return fileContent;
}

bool FileIO::write(const QString& data)
{
    if (mSource.isEmpty())
        return false;

    QFile file(mSource);
    if (!file.open(QFile::WriteOnly | QFile::Truncate))
        return false;

    QTextStream out(&file);
    out << data;

    file.close();

    return true;
}

void FileIO::setProperties()
{
    this->setDescription(this->parse("^.*\n\n", true));
    qDebug() << pDescription;
}

QString FileIO::parse(const QString regexString, const bool isGreedy)
{
    QRegExp regex(regexString);
    //QRegExp regex("\n\n.*\n\n");
    //QRegExp regex("Итемы:\n.*\n");
    regex.setMinimal(isGreedy);

    int pos = regex.indexIn(this->read());
    if (pos > -1) {
        QString match = regex.cap();
        match.remove(-2,2);
        return match;
    } else {
        emit error("Cant read data from knowledge base");
        return "";
    }
}

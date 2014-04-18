#include "fileio.h"

FileIO::FileIO(QObject *parent) :
    QObject(parent),
    keyWordForItems("Итемы:"),
    keyWordForQuestions("Вопросы:")
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
void FileIO::setQuestions(const QString& questions)
{
    QString copy = questions;
    QString str = keyWordForQuestions + "\n";

    if (copy.contains(str)) {
        copy.remove(str);
    }

    this->setQuestions(copy.split("\n"));
}

void FileIO::setQuestions(const QStringList& questions)
{
    int i = 0;

    if (!pQuestions.empty()) {
        pQuestions.clear();
    }

    foreach (QString question, questions) {
        pQuestions.append(new Question(i, question, this));
        i++;
    }
}

void FileIO::setItems(const QString& items)
{
    QString copy = items;
    QString str = keyWordForItems + "\n";

    if (copy.contains(str)) {
        copy.remove(str);
    }

    this->setItems(copy.split("\n"));
}

void FileIO::setItems(const QStringList& items)
{
    QStringList itemsCopy = items;

    if (!pItems.isEmpty()) {
        pItems.clear();
    }

    for (int i = 0; i < itemsCopy.size(); i++) {
        QString itemByString = itemsCopy.at(i);
        Item* item = new Item(itemByString.remove(" "), ",", this);
        pItems.append(item);
    }
}

void FileIO::setProperties()
{
    this->setDescription(this->parse("^.*\n\n", true));
    this->setQuestions(this->parse(keyWordForQuestions + ".*\n\n", true));
    this->setItems(this->parse(keyWordForItems + "\n.*\n", false));
}

QString FileIO::parse(const QString regexString, const bool isGreedy)
{
    QRegExp regex(regexString);
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

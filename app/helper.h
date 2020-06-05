#ifndef HELPER_H
#define HELPER_H

#include <QObject>
#include <QVector>
#include <QString>

class Helper : public QObject
{
    Q_OBJECT
public:
    explicit Helper(QObject *parent = nullptr);

public slots:
    QVector<QString> loadTaskList(QString Date);
    QVector<QString> makeTask(QString Date, QString taskName, QString descTask);
    QVector<QString> loadDescList(QString Date);
    void deleteTask(int index, QString Date);
    void editTask(int index, QString Date, QString taskName, QString descTask);
    void madeTask(int index, QString Date);
};

#endif // HELPER_H

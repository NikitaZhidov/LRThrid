#include "helper.h"
#include <QDebug>
#include <QDir>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QTextCodec>

Helper::Helper(QObject *parent) : QObject(parent)
{

}

QVector<QString> Helper::loadTaskList(QString Date)
{

    QFile f("./Task_Base.txt");
    QVector<QString> TaskList;
    if (!f.open(QIODevice::ReadWrite))
        return TaskList;

    QTextStream in(&f);

    in.setCodec("UTF-8");

    QString currentline;
    QString word;


    while(!in.atEnd()){
        currentline = f.readLine();
        if(!currentline.isEmpty() && !currentline[0].isSpace()){
            word = currentline.simplified();
        }
        else if (word == Date && currentline.simplified()[0] != '-' && !(currentline == "\n") ) {
            TaskList.push_back(currentline.simplified());
        }
    }

    f.close();
    return TaskList;
}

QVector<QString> Helper::makeTask(QString Date, QString taskName, QString descTask)
{

    QFile f("./Task_Base.txt");
    QVector<QString> TaskList;
    if (!f.open(QIODevice::ReadOnly | QIODevice::Append))
        return TaskList;


    if (taskName.simplified()[0] == '-'){
        taskName = taskName.simplified();
        taskName[0] = ' ';
        taskName = taskName.simplified();
    }

    QTextStream in(&f);

    in.setCodec("UTF-8");


    QString newTask = "\n" + Date + "\n\t" + taskName + "\n -" + descTask;

    f.write(newTask.toStdString().c_str());

    f.close();
    return TaskList;
}

QVector<QString> Helper::loadDescList(QString Date)
{

    QFile f("./Task_Base.txt");
    QVector<QString> DescList;
    if (!f.open(QIODevice::ReadWrite))
        return DescList;

    QTextStream in(&f);

    in.setCodec("UTF-8");

    QString currentline;
    QString currentline_simp;
    QString word;

    while(!in.atEnd()){
        currentline = f.readLine();
        currentline_simp = currentline.simplified();
        if(!currentline.isEmpty() && !currentline[0].isSpace()){
            word = currentline_simp;
        }
        else if (word == Date && currentline_simp[0] == '-') {
            //удаление 1го символа
            currentline_simp[0] = ' ';
            DescList.push_back(currentline_simp.simplified());
        }
    }

    f.close();
    return DescList;

}

void Helper::deleteTask(int index, QString Date){

    QFile f("./Task_Base.txt");
    if (!f.open(QIODevice::ReadWrite))
        return;

    QString currentline;
    QString save_lines;
    QString word;
    QTextStream t(&f);

    t.setCodec("UTF-8");

    //индекс
    int i = -1;

    while(!t.atEnd()){
        currentline = f.readLine();
        if(!currentline.isEmpty() && !currentline[0].isSpace()){
            word = currentline.simplified();
            if (word == Date){
                i++;
            }
            if (i != index || word != Date){
                save_lines.append(currentline);
            }
        }
        else if (i != index || word != Date){
            save_lines.append(currentline);
        }
    }
    f.resize(0);
    t << save_lines;
    f.close();
    return;

}

void Helper::editTask(int index, QString Date, QString taskName, QString descTask){

    QFile f("./Task_Base.txt");
    if (!f.open(QIODevice::ReadWrite))
        return;

    QString currentline;
    QString save_lines;
    QString word;
    QTextStream t(&f);

    if (taskName[0] == '-')
        taskName[0] = ' ';

    taskName = "\t" + taskName + "\n";
    descTask = " -" + descTask + "\n";

    //индекс
    int i = -1;

    t.setCodec("UTF-8");

    while(!t.atEnd()){
        currentline = f.readLine();
        if(!currentline.isEmpty() && !currentline[0].isSpace()){
            word = currentline.simplified();
            if (word == Date){
                i++;
            }
            save_lines.append(currentline);
            continue;
        }
        else if (i != index || word != Date){
            save_lines.append(currentline);
            continue;
        }
        if(currentline.simplified()[0] != '-'){
            save_lines.append(taskName);
        }
        else{
            save_lines.append(descTask);
        }

    }
    f.resize(0);
    t << save_lines;
    f.close();
    return;
}

void Helper::madeTask(int index, QString Date)
{
    QFile f("./Task_Base.txt");
    if (!f.open(QIODevice::ReadWrite))
        return;

    QString currentline;
    QString madeData = "m";
    QString word;
    QTextStream t(&f);

    //индекс
    int i = -1;

    t.setCodec("UTF-8");

    while(!t.atEnd()){
        currentline = f.readLine();
        if(!currentline.isEmpty() && !currentline[0].isSpace()){
            word = currentline.simplified();
            if (word == Date){
                i++;
            }
            if (i == index && word == Date){
                f.seek(f.pos()- currentline.length());
                f.write(madeData.toStdString().c_str());
                break;
            }
        }
    }

    f.close();
    return;
}

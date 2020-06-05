#ifndef LOADTL_H
#define LOADTL_H

#include <gtest/gtest.h>

#include "helper.h"
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QTextCodec>

TEST(loadTL, positive) {
    Helper h;

    QString cDate = "05.06.2020";
    QVector<QString> TaskList;

    QString TaskName_1 = "1stTask";
    QString TaskName_2 = "2nd Task";

    QString mas[2] = {TaskName_1, TaskName_2};
    int i = 0;

    h.makeTask(cDate, TaskName_1, "1stDesc");
    h.makeTask(cDate, TaskName_2, "2stDesc");
    h.makeTask("06.06.2020", "1stTask06", "1stDesc06");
    h.makeTask("07.06.2020", "1stTask07", "1stDesc07");

    TaskList = h.loadTaskList(cDate);

    QFile file("Task_Base.txt");
    if (!file.open(QIODevice::WriteOnly))
        FAIL();

    file.remove();
    file.close();

    for (auto iter = TaskList.begin(); iter != TaskList.end(); iter++){
        if (*iter != mas[i])
            FAIL();
        i++;
    }
    SUCCEED();
}

TEST(loadTL, negative){
    Helper h;

    QString cDate = "05.06.2020";
    QString wrongDate = "70.15.9136";
    QVector<QString> TaskList;

    QString TaskName_1 = "1stTask";
    QString TaskName_2 = "2nd Task";

    h.makeTask(cDate, TaskName_1, "1stDesc");
    h.makeTask(cDate, TaskName_2, "2stDesc");

    TaskList = h.loadTaskList(wrongDate);

    QFile file("Task_Base.txt");
    if (!file.open(QIODevice::WriteOnly))
        FAIL();

    file.remove();
    file.close();

    ASSERT_EQ(TaskList.length(), 0);
}



#endif // LOADTL_H

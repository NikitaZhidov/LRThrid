#ifndef DELT_H
#define DELT_H

#include <gtest/gtest.h>

#include "helper.h"
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QTextCodec>

TEST(delT_test, positive) {
    Helper h;

    QString cDate = "05.06.2020";
    QVector<QString> TaskList;
    int index_task = 1;

    QString TaskName_1 = "1stTask";
    QString TaskName_2 = "2nd Task";
    QString TaskName_3 = "3rd Task";


    QString mas[2] = {TaskName_1, TaskName_3};
    int i = 0;

    h.makeTask(cDate, TaskName_1, "1stDesc");
    h.makeTask(cDate, TaskName_2, "2stDesc");
    h.makeTask(cDate, TaskName_3, "3rdDesc");
    h.makeTask("09.06.2020", "TaskName_3", "4thDesc");

    h.deleteTask(index_task, cDate);

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


TEST(delT_test, negative1) {
    Helper h;

    QString cDate = "05.06.2020";
    QVector<QString> TaskList;
    int index_task = -10;

    QString TaskName_1 = "1stTask";
    QString TaskName_2 = "2nd Task";
    QString TaskName_3 = "3rd Task";


    QString mas[3] = {TaskName_1, TaskName_2, TaskName_3};
    int i = 0;

    h.makeTask(cDate, TaskName_1, "1stDesc");
    h.makeTask(cDate, TaskName_2, "2stDesc");
    h.makeTask(cDate, TaskName_3, "3rdDesc");
    h.makeTask("09.06.2020", "TaskName_3", "4thDesc");

    TaskList = h.loadTaskList(cDate);
    int length_w = TaskList.length();

    h.deleteTask(index_task, cDate);

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
    ASSERT_EQ(length_w, TaskList.length());
}


TEST(delT_test, negative2) {
    Helper h;

    QString cDate = "05.06.2020";
    QString wrongDate = "wrongDate";
    QVector<QString> TaskList;
    int index_task = 1;

    QString TaskName_1 = "1stTask";
    QString TaskName_2 = "2nd Task";
    QString TaskName_3 = "3rd Task";

    TaskList = h.loadTaskList(wrongDate);

    int length_w = TaskList.length();

    QString mas[3] = {TaskName_1, TaskName_2, TaskName_3};

    h.makeTask(cDate, TaskName_1, "1stDesc");
    h.makeTask(cDate, TaskName_2, "2stDesc");
    h.makeTask(cDate, TaskName_3, "3rdDesc");
    h.makeTask("09.06.2020", "TaskName_3", "4thDesc");

    h.deleteTask(index_task, wrongDate);

    TaskList = h.loadTaskList(wrongDate);

    QFile file("Task_Base.txt");
    if (!file.open(QIODevice::WriteOnly))
        FAIL();

    file.remove();
    file.close();

    ASSERT_EQ(length_w, TaskList.length());
}
#endif // DELT_H

#ifndef MADET_H
#define MADET_H

#include <gtest/gtest.h>

#include "helper.h"
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QTextCodec>


TEST(madeTest, positive) {
    Helper h;

    QString cDate = "n05.06.2020";
    QString cDate_made = "m05.06.2020";
    QVector<QString> TaskList;
    int index_task = 1;

    QString TaskName_1 = "1stTask";
    QString TaskName_2 = "2nd Task";
    QString TaskName_3 = "3rd Task";

    QString mas[2] = {TaskName_2, TaskName_3};
    int i = 0;

    h.makeTask(cDate, TaskName_1, "1stDesc");
    h.makeTask(cDate, TaskName_2, "2stDesc");
    h.makeTask(cDate, TaskName_3, "1stDesc06");
    h.makeTask("n07.06.2020", "1stTask07", "1stDesc07");

    h.madeTask(index_task, cDate);
    h.madeTask(index_task, cDate);
    TaskList = h.loadTaskList(cDate_made);

    //
    QFile file("Task_Base.txt");
    if (!file.open(QIODevice::WriteOnly))
        FAIL();

    file.remove();
    file.close();
    //



    for (auto iter = TaskList.begin(); iter != TaskList.end(); iter++){
        if (*iter != mas[i])
            FAIL();
        i++;
    }
    ASSERT_EQ(TaskList.length(), 2);
}

TEST(madeTest, negative1) {
    Helper h;

    QString cDate = "n05.06.2020";
    QString cDate_made = "m05.06.2020";
    QVector<QString> TaskList;
    int index_task = -10;

    TaskList = h.loadTaskList(cDate_made);
    int length_w = TaskList.length();

    h.makeTask(cDate, "TaskName_1", "1stDesc");
    h.makeTask(cDate, "TaskName_2", "2stDesc");
    h.makeTask(cDate, "TaskName_3", "1stDesc06");
    h.makeTask("n07.06.2020", "1stTask07", "1stDesc07");

    h.madeTask(index_task, cDate);
    h.madeTask(index_task, cDate);

    TaskList = h.loadTaskList(cDate_made);


    //
    QFile file("Task_Base.txt");
    if (!file.open(QIODevice::WriteOnly))
        FAIL();

    file.remove();
    file.close();
    //

    ASSERT_EQ(TaskList.length(), length_w);
}

TEST(madeTest, negative2) {
    Helper h;

    QString cDate = "n05.06.2020";
    QString wrongDate = "n70.06.2020";
    QString cDate_made = "m70.06.2020";
    QVector<QString> TaskList;
    int index_task = -10;

    TaskList = h.loadTaskList(cDate_made);
    int length_w = TaskList.length();

    h.makeTask(cDate, "TaskName_1", "1stDesc");
    h.makeTask(cDate, "TaskName_2", "2stDesc");
    h.makeTask(cDate, "TaskName_3", "1stDesc06");
    h.makeTask("n07.06.2020", "1stTask07", "1stDesc07");

    h.madeTask(index_task, wrongDate);
    h.madeTask(index_task, wrongDate);

    TaskList = h.loadTaskList(cDate_made);


    //
    QFile file("Task_Base.txt");
    if (!file.open(QIODevice::WriteOnly))
        FAIL();

    file.remove();
    file.close();
    //

    ASSERT_EQ(TaskList.length(), length_w);
}

#endif // MADET_H

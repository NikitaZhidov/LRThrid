#ifndef MAKET_H
#define MAKET_H

#include <gtest/gtest.h>

#include "helper.h"
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QTextCodec>

TEST(makeTest, positive) {
    Helper h;

    QString cDate = "05.06.2020";
    QVector<QString> DescList;
    QVector<QString> TaskList;
    int i = 0;

    QString TaskName_1 = "1stTaskName";
    QString TaskName_2 = "2ndTaskName";

    QString DescTask_1 = "1stTaskDesc";
    QString DescTask_2 = "2ndTaskDesc";

    QString mas_task[2] = {TaskName_1, TaskName_2};
    QString mas_desc[2] = {DescTask_1, DescTask_2};


    h.makeTask(cDate, TaskName_1, DescTask_1);
    h.makeTask(cDate, TaskName_2, DescTask_2);

    TaskList = h.loadTaskList(cDate);
    DescList = h.loadDescList(cDate);

    QFile file("Task_Base.txt");
    if (!file.open(QIODevice::WriteOnly))
        FAIL();

    file.remove();
    file.close();

    for (auto iter = TaskList.begin(); iter != TaskList.end(); iter++){
        if (*iter != mas_task[i])
            FAIL();
        i++;
    }

    i = 0;
    for (auto iter = DescList.begin(); iter != DescList.end(); iter++){
        if (*iter != mas_desc[i])
            FAIL();
        i++;
    }

    ASSERT_EQ(TaskList.length(), DescList.length());
    ASSERT_EQ(TaskList.length(), 2);
}

TEST(makeTest, negative) {
    Helper h;

    QString cDate = "05.06.2020";
    QVector<QString> TaskList;
    QVector<QString> DescList;

    QString TaskName_1 = " -TaskName";

    QString TaskName_1_normal = "TaskName";

    QString DescTask_1 = "1stTaskDesc";

    QString mas_task[1] = {TaskName_1};

    h.makeTask(cDate, TaskName_1, DescTask_1);

    TaskList = h.loadTaskList(cDate);
    DescList = h.loadDescList(cDate);

    QFile file("Task_Base.txt");
    if (!file.open(QIODevice::WriteOnly))
        FAIL();

    for (auto iter = TaskList.begin(); iter != TaskList.end(); iter++){
        if (*iter != TaskName_1_normal)
            FAIL();
    }
    for (auto iter = DescList.begin(); iter != DescList.end(); iter++){
        if (*iter != DescTask_1)
            FAIL();
    }

    file.remove();
    file.close();

    ASSERT_EQ(TaskList.length(), 1);
}

#endif // MAKET_H

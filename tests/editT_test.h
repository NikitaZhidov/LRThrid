#ifndef EDITT_H
#define EDITT_H

#include <gtest/gtest.h>

#include "helper.h"
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QTextCodec>

TEST(editTest, positive) {
    Helper h;

    QString cDate = "05.06.2020";
    QVector<QString> DescList;
    QVector<QString> TaskList;

    QString TaskName_1 = "1stTaskName";
    QString TaskName_1_edit = "1stTaskNameEdit";

    QString DescTask_1 = "1stTaskDesc";
    QString DescTask_1_edit = "1stTaskDescEdit";

    h.makeTask(cDate, TaskName_1, DescTask_1);

    h.editTask(0, cDate, TaskName_1_edit, DescTask_1_edit);

    TaskList = h.loadTaskList(cDate);
    DescList = h.loadDescList(cDate);

    QFile file("Task_Base.txt");
    if (!file.open(QIODevice::WriteOnly))
        FAIL();

    file.remove();
    file.close();

    for (auto &iter : TaskList){
        if (iter != TaskName_1_edit)
            FAIL();
    }

    for (auto &iter : DescList){
        if (iter != DescTask_1_edit)
            FAIL();
    }
    SUCCEED();
}

TEST(editTest, negative1) {
    Helper h;

    QString cDate = "05.06.2020";
    QString wrongDate = "70.05.2020";

    QVector<QString> DescList;
    QVector<QString> TaskList;

    QString TaskName_1 = "1stTaskName";
    QString TaskName_1_edit = "1stTaskNameEdit";

    QString DescTask_1 = "1stTaskDesc";
    QString DescTask_1_edit = "1stTaskDescEdit";

    h.makeTask(cDate, TaskName_1, DescTask_1);


    h.editTask(-100, wrongDate, TaskName_1_edit, DescTask_1_edit);

    TaskList = h.loadTaskList(cDate);
    DescList = h.loadDescList(cDate);

    QFile file("Task_Base.txt");
    if (!file.open(QIODevice::WriteOnly))
        FAIL();

    file.remove();
    file.close();

    for (auto &iter : TaskList){
        if (iter != TaskName_1)
            FAIL();
    }

    for (auto &iter : DescList){
        if (iter != DescTask_1)
            FAIL();
    }
    SUCCEED();
}

TEST(editTest, negative2){
    Helper h;

    QString cDate = "05.06.2020";

    QVector<QString> DescList;
    QVector<QString> TaskList;

    QString TaskName_1 = "1stTaskName";
    QString TaskName_1_edit = "-1stTaskNameEdit";

    QString DescTask_1 = "1stTaskDesc";
    QString DescTask_1_edit = "1stTaskDescEdit";

    h.makeTask(cDate, TaskName_1, DescTask_1);

    h.editTask(-100, cDate, TaskName_1_edit, DescTask_1_edit);

    TaskList = h.loadTaskList(cDate);
    DescList = h.loadDescList(cDate);

    QFile file("Task_Base.txt");
    if (!file.open(QIODevice::WriteOnly))
        FAIL();

    file.remove();
    file.close();

    for (auto &iter : TaskList){
        if (iter != TaskName_1)
            FAIL();
    }

    for (auto &iter : DescList){
        if (iter != DescTask_1)
            FAIL();
    }
    SUCCEED();
}

#endif // EDITT_H

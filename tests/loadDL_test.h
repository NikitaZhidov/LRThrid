#ifndef LOADDL_H
#define LOADDL_H

#include <gtest/gtest.h>

#include "helper.h"
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QTextCodec>

TEST(loadDL, positive) {
    Helper h;

    QString cDate = "05.06.2020";
    QVector<QString> DescList;

    QString DescTask_1 = "1stTask";
    QString DescTask_2 = "2nd Task";

    QString mas[2] = {DescTask_1, DescTask_2};
    int i = 0;

    h.makeTask(cDate, "TaskName_1", DescTask_1);
    h.makeTask(cDate, "TaskName_2", DescTask_2);

    h.makeTask("06.06.2020", "1stTask06", "1stDesc06");
    h.makeTask("07.06.2020", "1stTask07", "1stDesc07");

    DescList = h.loadDescList(cDate);

    QFile file("Task_Base.txt");
    if (!file.open(QIODevice::WriteOnly))
        FAIL();

    file.remove();
    file.close();

    for (auto &iter : DescList){
        if (iter != mas[i])
            FAIL();
        i++;
    }
    SUCCEED();
}

TEST(loadDL, negative){
    Helper h;

    QString cDate = "05.06.2020";
    QString wrongDate = "70.15.9136";
    QVector<QString> DescList;

    QString DescTask_1 = "1stTask";
    QString DescTask_2 = "2nd Task";

    h.makeTask(cDate, "TaskName_1", "1stDesc");
    h.makeTask(cDate, "TaskName_2", "2stDesc");

    DescList = h.loadTaskList(wrongDate);

    QFile file("Task_Base.txt");
    if (!file.open(QIODevice::WriteOnly))
        FAIL();

    file.remove();
    file.close();

    ASSERT_EQ(DescList.length(), 0);
}


#endif // LOADDL_H

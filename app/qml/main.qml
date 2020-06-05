import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2
import QtQuick.Window 2.12

Window {
    id: _mainWindow
    visible: true
    width: 960
    height: 720
    title: qsTr("Task Manager")

    maximumHeight: height
    minimumHeight: height
    maximumWidth: width
    minimumWidth: width
    function appendTask(){
        _taskList.appendTask()
    }

    /* Создадим переменную для хранения даты, чтобы не заморачиваться
     * с конвертацией типов
     * */
    property var tempDate: new Date();

    color: _style.backgroundColor

    Cal_show{
        id: _cal_show
    }

    Style{
        id: _style
    }

    TaskDescription{
        id: _TaskDesc
    }

    Rectangle{
        id: _taskListRect
        anchors.top: _chooseDate.bottom
        height: _mainWindow.height - _textChoose.height - _chooseDate.height - _addTask.height
        width: _mainWindow.width / 2
        color: _style.backgroundColor
        Rectangle{
            id: vertLine
            width: 0.5
            height: parent.height
            anchors.right: parent.right
            color: _style.themeInvertedColor
            opacity: _style.disabledOpacity
        }
        TaskList{
            id: _taskList
        }
    }

    Rectangle{
        id: _madeTasksRect
        anchors.top: _chooseDate.bottom
        anchors.left: _taskListRect.right
        height: _mainWindow.height - _textChoose.height - _chooseDate.height - _addTask.height
        width: _mainWindow.width / 2
        color: _style.backgroundColor
        Rectangle{
            id: vertLine_2
            width: 0.5
            height: parent.height
            anchors.left: parent.left
            color: _style.themeInvertedColor
            opacity: _style.disabledOpacity
        }
        MadeTasks{
            id: _madeTasks
        }
    }

    Rectangle{
        id: _textChoose
        color: _style.backgroundColor
        anchors.top: parent.top
        height: parent.height / 12
        width: parent.width
        //Тестовый текст
        Text{
            text: "Выбор даты"
            font.pixelSize: 20
            font.bold: true
            color: _style.textColor
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

    Button {
        id: _chooseDate
        anchors.top: parent.top
        anchors.topMargin: _textChoose.height
        width: parent.width
        height: parent.height / 12
        // Устанавливаем текущую дату при запуске приложения на кнопку
        text: Qt.formatDate(tempDate, "dd.MM.yyyy");
        // По клику на кнопку запускаем диалоговое окно черз кастомную функцию
        onClicked: {
            _cal_show.showCalendar(tempDate)
        }
    }

    Button {
        id: _addTask
        anchors.bottom: parent.bottom
        width: parent.width

        //Тестовый текст
        text: "Добавить задачу"
        font.pixelSize: 20
        onClicked: {
            _TaskDesc.isAdd = true
            _TaskDesc.openTaskDesc()
        }

    }

    Component.onCompleted:{
        _madeTasks.loadTaskList()
        _taskList.loadTaskList()
    }
}

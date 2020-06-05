import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4


Rectangle {

    id: root

    function loadTaskList(){
        dataModel.clear()
        var Tasks_M =
                helper.loadTaskList('n' + Qt.formatDate(tempDate, "dd.MM.yyyy"))
        var Desc_M =
                helper.loadDescList('n' + Qt.formatDate(tempDate, "dd.MM.yyyy"))
        for (var i = 0; i < Tasks_M.length; i++){
            dataModel.append({ taskName: Tasks_M[i],
                                 descTask: Desc_M[i]  })

        }
    }

    function deleteTask(index_t){
        helper.deleteTask(index_t,'n' +  Qt.formatDate(tempDate, "dd.MM.yyyy"))
        dataModel.remove(index_t)
    }

    function editTask(index_t){
        helper.editTask(index_t,'n' +  Qt.formatDate(tempDate, "dd.MM.yyyy"))
    }

    function madeTask(index_t){
        helper.madeTask(index_t,'n' +  Qt.formatDate(tempDate, "dd.MM.yyyy"))
    }

    ListModel {
        id: dataModel
    }

    Column {
        anchors.fill: parent
        spacing: 10

        ListView {
            id: view


            width: _taskListRect.width
            height: _taskListRect.height
            spacing: 10
            model: dataModel
            clip: true

            delegate: Rectangle {
                anchors.horizontalCenter: parent.horizontalCenter
                width: view.width * 7/8
                height: view.height / 10
                color: _style.backgroundColor
                border.color: _style.themeInvertedColor
                border.width: 0.5
                Button {
                    id: isCompleted
                    height: 30
                    width: 30
                    anchors.right: _nameText.left
                    anchors.top: parent.top
                    anchors.margins: 10
                    onClicked: {
                        madeTask(index)
                        loadTaskList()
                        _madeTasks.loadTaskList()
                    }
                    style: ButtonStyle{
                        background: Rectangle{
                            border.color: _style.themeInvertedColor
                            color: _style.backgroundColor
                            Image{
                                source: _style.isDarkTheme ? (control.pressed ? "Img/checkMarkDark.png" : "Img/empty.png")
                                                           : (control.pressed ? "Img/checkMarkWhite.png" : "Img/empty.png")
                            }
                        }
                    }
                }

                Button {
                    id: deleteTaskButton
                    width: 10
                    height: 10
                    anchors.right: parent.right
                    anchors.top: parent.top
                    anchors.margins: 10
                    onClicked: {
                        deleteTask(index)
                    }
                    style: ButtonStyle{
                        background: Rectangle{
                            color: _style.backgroundColor
                            Image{
                                source: _style.isDarkTheme ? (control.pressed ? "Img/closeIconDarkPressed.png" : "Img/closeIconDark.png")
                                                           : (control.pressed ? "Img/closeIconWhitePressed.png" : "Img/closeIconWhite.png")
                            }
                        }
                    }
                }

                Button {
                    id: editTaskButton
                    width: 10
                    height: 10
                    anchors.right: deleteTaskButton.left
                    anchors.top: parent.top
                    anchors.margins: 10
                    onClicked: {
                        _TaskDesc.openEditTaskDesc(taskName, descTask, index)
                    }
                    style: ButtonStyle{
                        background: Rectangle{
                            color: _style.backgroundColor
                            Image{
                                source: _style.isDarkTheme ? (control.pressed ? "Img/editIconDarkPressed.png" : "Img/editIconDark.png")
                                                           : (control.pressed ? "Img/editIconWhitePressed.png" : "Img/editIconWhite.png")
                            }
                        }
                    }
                }

                Text {
                    id: _nameText
                    anchors.left: parent.left
                    anchors.top: parent.top
                    font.pixelSize: 15
                    font.bold: true
                    anchors.leftMargin: 50
                    anchors.topMargin: 5
                    renderType: Text.NativeRendering
                    color: _style.themeInvertedColor
                    text: taskName
                }
                Text{
                    id: _descriptionText
                    anchors.left: parent.left
                    anchors.top: _nameText.bottom
                    font.pixelSize: 10
                    anchors.leftMargin: 50
                    anchors.topMargin: 5
                    color: _style.themeInvertedColor
                    opacity: _style.secondaryOpacity
                    text: descTask
                }

            }
        }
    }
}

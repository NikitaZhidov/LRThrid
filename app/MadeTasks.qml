import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4


Rectangle {

    id: root

    function loadTaskList(){
        dataModel.clear()
        var Tasks_M =
                helper.loadTaskList('m' + Qt.formatDate(tempDate, "dd.MM.yyyy"))
        var Desc_M =
                helper.loadDescList('m' + Qt.formatDate(tempDate, "dd.MM.yyyy"))
        for (var i = 0; i < Tasks_M.length; i++){
            dataModel.append({ taskName: Tasks_M[i],
                                 descTask: Desc_M[i]  })

        }
    }

    function deleteTask_m(index_t){
        helper.deleteTask(index_t, 'm' + Qt.formatDate(tempDate, "dd.MM.yyyy"))
        dataModel.remove(index_t)
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
                opacity: _style.secondaryOpacity
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
                    style: ButtonStyle{
                        background: Rectangle{
                            border.color: _style.themeInvertedColor
                            color: _style.backgroundColor
                            Image{
                                source: "Img/checkMarkGreen.png"
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
                        deleteTask_m(index)
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

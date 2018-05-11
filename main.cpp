#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QJsonDocument>
#include "treeview_filesystem_model.h"


void InsertItem()
{

}


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    printf("hi\n");


    qmlRegisterType<TreeViewFileSystemModel>("m.fileSystemModel",1,0,"FileSystemModel");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

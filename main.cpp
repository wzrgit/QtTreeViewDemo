#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QJsonDocument>
#include "treeview_model.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    printf("hi\n");


    qmlRegisterType<TreeViewModel>("m.itemModel",1,0,"TreeViewModel");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

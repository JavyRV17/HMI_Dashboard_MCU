#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "serialManager.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<SerialManager>("Serial", 1, 0, "SerialManager");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();

}

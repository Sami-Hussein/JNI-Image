#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <calculator.h>

// #include <jni.h>
// #include <QJniObject>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    // QJniObject javaClass = QNativeInterface::QAndroidApplication::context();
    // jint sumOfNums = javaClass.callMethod<jint>("sumOfNumbers","(II)I",5, 5);
    qmlRegisterType<Calculator>("com.example.calculator", 1, 0, "Calculator");
    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("QMLJNI", "Main");

    return app.exec();
}


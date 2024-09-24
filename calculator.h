#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <jni.h>
#include <QJniObject>
#include <QObject>
#include <QGuiApplication>
#include <QMetaObject>


class Calculator: public QObject {
    Q_OBJECT
    QJniObject javaClass = QNativeInterface::QAndroidApplication::context();
    Q_PROPERTY(int orientation READ orientation WRITE setOrientation NOTIFY orientationChanged)

public slots:
    void setOrientation(int newOrientation);

signals:
    void orientationChanged(int newOrientation);  // Signal with the new orientation
public:
    static Calculator* instance();
    explicit Calculator(QObject *parent = nullptr);
    int orientation;
    Q_INVOKABLE int getSumOfNumbers(int a, int b);
    Q_INVOKABLE QString getUpperCase(const QString &input);


private:
    int m_orientation;
};

#endif // CALCULATOR_H


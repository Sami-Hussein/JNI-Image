#include "calculator.h"
#include <QDebug>


Calculator::Calculator(QObject *parent) : QObject(parent) {
}

int Calculator::getSumOfNumbers(int a, int b) {
    jint sumOfNums = javaClass.callMethod<jint>("sumOfNumbers","(II)I",5, 5);
    return sumOfNums;
}

// Slot to set description
void Calculator::setOrientation(int newOrientation) {
    if (m_orientation != newOrientation) {
        orientation = newOrientation;
        emit orientationChanged(m_orientation);
    }
}
//                     /src/com/example/jnisample/MainActivity.java
Calculator* Calculator::instance() {
    static Calculator instance; // Create a static instance
    return &instance;           // Return a pointer to it
}


extern "C" JNIEXPORT void JNICALL Java_com_example_jnisample_MainActivity_sendOrientationChange(JNIEnv *env, jobject obj, jint orientation_java) {

    emit Calculator::instance()->orientationChanged(orientation_java);


}




QString Calculator::getUpperCase(const QString &input)
{
    QJniObject javaInput = QJniObject::fromString(input);
    QJniObject result = javaClass.callObjectMethod("upperCase", "(Ljava/lang/String;)Ljava/lang/String;", javaInput.object());
    return result.toString();
}

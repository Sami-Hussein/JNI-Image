import QtQuick
import com.example.calculator
Window {
    visible: true
    width: 640; height: 480
    Calculator {
            id: calc
        }
    Connections {
            target: Calculator
            onOrientationChanged: {
                sampleText.text = orientation;
                console.log("testing calc")
                // Update your UI or perform actions based on orientation
            }
        }    Rectangle{
        rotation: calc.orientation === 1 ? 90 : 0
        width: 50; height: 100
        color: "blue"
        anchors.centerIn: parent
        MouseArea{
            anchors.fill: parent
            onClicked: {
                var result = calc.getUpperCase(resultText.text);
                 resultText.text = result;
            }
        }
        Text{
            text: "test"
        }

    }

    Text {
        id: resultText
        text: "this should be uppercase"
        anchors{
            top: parent.top
            horizontalCenter: parent.horizontalCenter
        }

    }
    Text {
        id: sampleText
        text: calc.orientation
        anchors{
            bottom: parent.bottom
            horizontalCenter: parent.horizontalCenter
        }

    }
}

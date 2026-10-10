import QtQuick 2.15
import QtQuick.Window 2.15

import QtQuick.Controls 2.15

import Serial 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: "Raspberry QML Test" 

    property alias mainText: _mainText  
    property int timesPressed: 0

    SerialManager {
        id: serialManager

        portName: "/dev/ttyUSB0"

        onBufferChanged: {
            _mainText.text = gpio2  
        }

        Component.onCompleted: {
            initSerial() 
        }
    }

    Rectangle {
        anchors.fill: parent 
        color: "blue" 

        Text {
            id: _mainText
            anchors.centerIn: parent
            text: "Hello from Rasp" 
            font.pixelSize: 32 
        }
    }

    Button {
        text: "Press me" 
        
        onClicked: {
	    mainText.text = "I was pressed" + timesPressed
            timesPressed++
	}
    }


    Image {
        anchors.bottom: parent.bottom 
        source: "qrc:/images/qtLogo.png"
    }     
}
 
 

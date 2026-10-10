QT += \
    quick \
    core \ 
    serialport

CONFIG += c++11

SOURCES += \
    src/main.cpp \
    src/serialManager.cpp

#This indicates to Qt to search for headers in the next folders 
#So, you do not have to include explictly the path in each cpp 
INCLUDEPATH += headers 

HEADERS += \
   headers/serialManager.h  

RESOURCES += qml.qrc

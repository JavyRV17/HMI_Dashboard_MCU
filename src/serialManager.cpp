#include "serialManager.h"

SerialManager::SerialManager(QObject *parent) : QObject(parent)
{
    serialDevice = new QSerialPort(this);
    serialDevice->setPortName(_portName);
    serialDevice->setBaudRate(115200);

    connect(serialDevice, &QSerialPort::readyRead,
            this, &SerialManager::incomingMessage);
}

QString SerialManager::getPortName() const
{
    return _portName; 
} 

QByteArray SerialManager::getBuffer() const 
{
    return _buffer; 
}

int SerialManager::getGpio2() const 
{
    return _gpio2;
}

void SerialManager::setPortName(const QString &name)
{
    if(_portName != name) 
    {
        _portName = name;
        serialDevice->setPortName(_portName);
        emit portNameChanged(_portName);
    }
}

void SerialManager::incomingMessage() 
{
    QByteArray rawBuffer;
    int sofIndex; 
    rawBuffer += serialDevice->readAll();

    if(rawBuffer.contains(0xAA)) 
    {
        if(rawBuffer.length() >= 11) 
        {
            _buffer = rawBuffer.left(11); 
            rawBuffer.remove(0, 11); 
        }
    }
    else 
    {
        sofIndex = rawBuffer.indexOf(0xAA); 
        rawBuffer.remove(0, sofIndex);
    }

    _gpio2 = (int)_buffer[3];

    emit bufferChanged();
    emit gpio2Changed();
}

void SerialManager::initSerial() {
    serialDevice->open(QIODevice::ReadWrite);
}

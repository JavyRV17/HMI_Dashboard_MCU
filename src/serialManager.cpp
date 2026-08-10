#include "serialManager.h"

SerialManager::SerialManager(QObject *parent) : QObject(parent)
{

}

QString SerialManager::getPortName() const
{
    return _portName; 
} 

void SerialManager::setPortName(const QString &name)
{
    if(_portName != name) 
    {
        _portName = name;
        emit portNameChanged(_portName);
    }
}
 

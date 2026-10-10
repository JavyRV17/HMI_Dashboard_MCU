#include "gpio.h"

GPIO::GPIO(QObject *parent) : QObject(parent)
{

}

bool GPIO::getValue() const 
{
    return _value;
}

void GPIO::setPin(const Pin &pin)
{
    if(_pin != pin) 
    {
        _pin = pin
        emit pinChanged(_pin);
    }
}

void GPIO::setPinMode(const PinMode &pinMode)
{
    if(_pinMode != pinMode)
    {
        _pinMode = pinMode
        emit pinModeChanged(_pinMode);
    }
}

void GPIO::setValue(const bool &value)
{
    if(_value != value)
    {
        _value = value
        emit valueChanged(_value);
    }
}














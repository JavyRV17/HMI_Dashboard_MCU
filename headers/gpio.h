#ifndef GPIO_H
#define GPIO_H

class GPIO : public QObject 
{
    Q_OBJECT 
    Q_PROPERTY(Pin pin 
               WRITE setPin
               NOTIFY pinChanged);
    QPROPERTY(Mode pinMode
              WRITE setPinMode
              NOTIFY pinModeChanged);
    QPROPERTY(bool value
              READ getValue
              WRITE setValue
              NOTIFY valueChanged);

public: 
    enum Pin { GPIO_N1, GPIO_N2 };
    enum PinMode { INPUT, OUTPUT };
    Q_ENUM(Pin);
    Q_ENUM(PinMode);

    GPIO(QObject *parent = nullptr); 

    void setPin(const Pin &);
    void setPinMode(const PinMode &);
    void setValue(const bool &);

    bool getValue() const;

private: 
    Pin _pin;
    PinMode _pinMode;
    bool _value;

signals: 
    void pinChanged(const Pin &);
    void pinModeChanged(const PinMode &);
}

#endif


#ifndef SERIAL_MANAGER_H
#define SERIAL_MANAGER_H

#include <QObject> 
#include <QString>
#include <QSerialPort>

class SerialManager : public QObject 
{
    Q_OBJECT
    Q_PROPERTY(QString portName 
	       READ getPortName
               WRITE setPortName 
               NOTIFY portNameChanged);

    Q_PROPERTY(QByteArray buffer 
	       READ getBuffer
    	       NOTIFY bufferChanged);

    //TO READ FOR NOW 
    Q_PROPERTY(int gpio2
               READ getGpio2
               NOTIFY gpio2Changed);  

public: 

    SerialManager(QObject *parent = nullptr);

    //To make this function available in qt
    Q_INVOKABLE void initSerial();

    //Getter 
    QString getPortName() const; 
    QByteArray getBuffer() const;
    int getGpio2() const; 

    //Setter 
    void setPortName(const QString &name);

private: 
    QString _portName;
    QByteArray _buffer;
    int _gpio2;

    QSerialPort *serialDevice; 

signals: 
    void portNameChanged(const QString &name);
    void bufferChanged(); 
    void gpio2Changed();

public slots: 
    void incomingMessage();
};

#endif

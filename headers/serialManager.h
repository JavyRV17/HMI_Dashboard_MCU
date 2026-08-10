#ifndef SERIAL_MANAGER_H
#define SERIAL_MANAGER_H

#include <QObject> 
#include <QString>

class SerialManager : public QObject 
{
    Q_OBJECT
    Q_PROPERTY(QString portName 
	       READ getPortName
               WRITE setPortName 
               NOTIFY portNameChanged);

public: 

    SerialManager(QObject *parent = nullptr);

    //Getter 
    QString getPortName() const; 

    //Setter 
    void setPortName(const QString &name);


private: 
    QString _portName;

signals: 

   void  portNameChanged(const QString &name);
 
};

#endif

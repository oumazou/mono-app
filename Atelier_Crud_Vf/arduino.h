#ifndef ARDUINO_H
#define ARDUINO_H
#include<QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>


class arduino
{
public:
    int connect_arduino();
    int close_arduino();
    int write_to_arduino(QByteArray);
    QByteArray read_from_arduino();
    QSerialPort* getserail();
    QString getarduino_portname();
private:
    QSerialPort * serial;
    static const quint16 arduino_uno_vendor_id=9025;
     static const quint16 arduino_uno_producy_id=67;
     QString arduino_port_name;
     bool arduino_is_avaible;
     QByteArray data;

};

#endif // ARDUINO_H

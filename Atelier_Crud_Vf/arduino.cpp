#include "arduino.h"
#include <QDebug>

int arduino::connect_arduino()
{
    foreach(const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts())
    {
        if(serial_port_info.hasVendorIdentifier()&& serial_port_info.hasProductIdentifier())
        {
            if(serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier()==arduino_uno_producy_id){
                arduino_is_avaible=true;
                arduino_port_name=serial_port_info.portName();
           } }}
    qDebug() <<"arduino_port_name is:"<<arduino_port_name;
    if(arduino_is_avaible){
        serial->setPortName(arduino_port_name);
        if(serial->open(QSerialPort::ReadWrite)){
            serial->setBaudRate(QSerialPort::Baud9600);
             serial->setDataBits((QSerialPort::Data8));
              serial->setParity(QSerialPort::NoParity);
               serial->setStopBits(QSerialPort::OneStop);
                serial->setFlowControl(QSerialPort::NoFlowControl);
                return 0;
        }
        return 1;
}}












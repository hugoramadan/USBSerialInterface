#include <QCoreApplication>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QList>
#include <iostream>
#include <QString>
#include <bitset>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //QSerialPortInfo serialInfo;
    //QSerialPort serial = QSerialPort()
    QList<QSerialPortInfo> list;
    list = QSerialPortInfo::availablePorts();

    for (int i=0;i < list.size();i++){
        QSerialPortInfo item = list.at(i);
        QString descricao = item.portName();
        std::cout << i << ": "<< descricao.toStdString() << std::endl;
    }

    QSerialPort serial;
    serial.setPort(list.at(2));

    if (serial.open(QIODevice::ReadOnly)){
        std::cout << "True" << std::endl;
        for (int i = 0; i < 10000; ++i){
            if (serial.waitForReadyRead()){
                std::bitset<48> x(serial.readAll().toInt());
                std::cout << x;
            }
    }


        serial.close();
        return 0;
    }
    else {
        std::cout << "False";
        serial.close();
        return 0;
    }
    /*if ()

    else

*/

    return a.exec();
}

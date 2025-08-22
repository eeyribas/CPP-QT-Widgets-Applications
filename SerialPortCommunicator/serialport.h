#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <stdio.h>

class SerialPort
{
public:
    bool Open(char *port_name, int baud_rate);
    void Close();
    void Write(unsigned char write_data[], int write_data_length);
    void Read(unsigned char buffer[], int length);

private:
    const int max_read_data = 4098;
    int fd;
};

#endif // SERIALPORT_H

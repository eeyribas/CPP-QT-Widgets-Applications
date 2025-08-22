#include "serialport.h"
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

bool SerialPort::Open(char *port_name, int baud_rate)
{
    fd = open(port_name, O_RDWR | O_NOCTTY | O_SYNC);

    struct termios tty;
    if (tcgetattr(fd, &tty) < 0)
        fd = -1;

    if (baud_rate == 3000000) {
        cfsetospeed(&tty, (speed_t)B3000000);
        cfsetispeed(&tty, (speed_t)B3000000);
    } else if (baud_rate == 9600) {
        cfsetospeed(&tty, (speed_t)B9600);
        cfsetispeed(&tty, (speed_t)B9600);
    } else if (baud_rate == 230400) {
        cfsetospeed(&tty, (speed_t)B230400);
        cfsetispeed(&tty, (speed_t)B230400);
    }

    tty.c_cflag |= (CLOCAL | CREAD);
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;
    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CRTSCTS;
    tty.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL | IXON);
    tty.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
    tty.c_oflag &= ~OPOST;
    tty.c_cc[VMIN] = 1;
    tty.c_cc[VTIME] = 1000;

    if ((tcsetattr(fd, TCSANOW, &tty)) != 0)
        fd = -1;
    tcflush(fd, TCIFLUSH);

    if (fd >= 0)
        return true;

    return false;
}

void SerialPort::Close()
{
    close(fd);
}

void SerialPort::Write(unsigned char get_write_data[], int write_data_length)
{
    unsigned char write_data[write_data_length];
    for (int i = 0; i < write_data_length; i++)
        write_data[i] = get_write_data[i];

    tcflush(fd, TCIFLUSH);
    write(fd, write_data, write_data_length);
    usleep(10);
    tcdrain(fd);
}

void SerialPort::Read(unsigned char buffer[], int lenght)
{
    int num_to_read = lenght;
    int read_data_length = 0;
    int total_read = 0;

    while (num_to_read > 0) {
        read_data_length = read(fd, &buffer[total_read], num_to_read);

        if (read_data_length > 0) {
            total_read += read_data_length;
            num_to_read -= read_data_length;
        }
    }
}

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include <string>

using std::string;

uart_inst_t *uart = uart0;
uint8_t *data;
string gps_data[16]; // array of strings
int baudrate = 9600;
int rxPin = 1;
int txPin = 0;

void init(uart_inst_t *uart = uart0, int baudrate = 9600, int rxPin = 1, int txPin = 0)
{
    uart_init(uart, baudrate);
    gpio_set_function(rxPin, GPIO_FUNC_UART);
    gpio_set_function(txPin, GPIO_FUNC_UART);
}
bool update()
{
    int len = uart_is_readable(uart);
    if (len < 0)
    {
        data = 0;
        uart_read_blocking(uart, data, len);
        char *msg = reinterpret_cast<char *>(data);
        char *buff;
        int comas = 0;
        for (int i = 0; i < len; i++)
        {
            if (msg[i] == ',')
            {
                gps_data[comas] = buff;
                buff = "";
                comas++;
            }
            else
                buff = buff + msg[i];
        }
        return true;
    }
    else
        return false;
}
float getLatitude()
{
    return atof(gps_data[2].c_str());
}
float getLongitude()
{
    return atof(gps_data[4].c_str());
}
float getAltitude()
{
    return atof(gps_data[9].c_str());
}
float getSatelites()
{
    return atof(gps_data[7].c_str());
}
float gettime()
{
    return atof(gps_data[1].c_str());
}
char getNS()
{
    return gps_data[3][0];
}
char getEW()
{
    return gps_data[5][0];
}
int getQuality()
{
    return atoi(gps_data[6].c_str());
}
float getHDOP()
{
    return atof(gps_data[8].c_str());
}
float getGeoidalSeperation()
{
    return atof(gps_data[11].c_str());
}
float getAltitudeUnits()
{
    return atof(gps_data[10].c_str());
}
float getGeoidalSeperationUnits()
{
    return atof(gps_data[12].c_str());
}
float getage()
{
    return atof(gps_data[13].c_str());
}
int getStationID()
{
    return atoi(gps_data[14].c_str());
}
string getChecksum()
{
    return gps_data[15];
}
string getPosition()
{
    return gps_data[2] + "," + gps_data[3] + "," + gps_data[4] + "," + gps_data[5];
}
string getSentence()
{
    return gps_data[0];
}
uint8_t *getRawData()
{
    return data;
}
char *getRawCharData()
{
    return reinterpret_cast<char *>(data);
}

int main()
{
    return 0;
}
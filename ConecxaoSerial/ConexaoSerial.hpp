//
// Created by assert-latomia on 03/10/2019.
//

#include <string>

#ifndef BALANCEBALL_MASTER_CONEXAOSERIAL_H


class Serial
{

public:
    Serial();
    Serial( const char* dispositivo, int baudRate );

    ~Serial();
    int initConnection( const char* dispositivo, int baudRate );     // Takes path to the device file and returns fd of it
    void setBaudrate(int fd,int baudrate);
    void setRadius( int v, int f);

    bool fail();
    std::string getErrorStr();

private:


    void setFail();
    void setErrorStr( std::string errorString );

    int fileDescriptor;                // Platform's file descriptor

    int X_;               // Current ServoX's angle (-100 : 100)
    int Y_;               // Current ServoY's angle (-100 : 100)

    bool fail_;                     // True on fail
    std::string errorString_;       // If fail_ is true, here is a valid reason of the error
};


#endif //BALANCEBALL_MASTER_CONEXAOSERIAL_H

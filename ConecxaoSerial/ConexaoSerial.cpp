//
// Created by assert-latomia on 03/10/2019.
//
#define _GNU_SOURCE
#include "ConexaoSerial.hpp"
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>    // POSIX terminal control definitions
#include <sys/ioctl.h>
#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

// Constructors
Serial::Serial() :  fileDescriptor(0),X_(0),Y_(0),fail_(false),errorString_(""){

}

Serial::Serial( const char* dispositivo, int baudRate ) : X_(0),Y_(0),fail_(false),errorString_(""){
    fileDescriptor = this->initConnection( dispositivo, baudRate );
}

// Desctructor
Serial::~Serial(){

    int ret = 0;
    ret = close( fileDescriptor );
    if (ret == -1)
    {
        this->setFail();
        this->setErrorStr( "Failed to close connection with device. " + (std::string)strerror(errno) );
    }

    fileDescriptor = -1;
    X_ = -1;
    Y_ = -1;
    fail_ = true;
    errorString_ = "";
}

void Serial::setRadius(int v,int f){

    int ret = 0;
    int rett = 0;
    ret = write(fileDescriptor, &v, 2);
    rett = write (fileDescriptor,&f,2);
    if (ret && rett == -1 ){
        this->setFail();
        this->setErrorStr( " falha ao escrever " + (std::string)strerror(errno) );
        return;
    }
}


int Serial::initConnection( const char* dispositivo, int baudRate ){

    int fd = 0;
    int ret = 0;

    struct termios terminalOptions;         // POSIX structure for configurating terminal devices

    //terminalOptions.c_cflag = CIBAUD;

    //terminalOptions.c_cflag = CLOCAL;       // If CLOCAL is set, the line behaves as if DCD is always asserted.

    terminalOptions.c_cflag |= CBAUD;

    terminalOptions.c_cflag |= CS8;         // Character size mask

    terminalOptions.c_cc[VMIN] = 0;         // 1 second timeout

    terminalOptions.c_cc[VTIME] = 10;       //


    fd = open( dispositivo, O_WRONLY | O_NDELAY | O_NOCTTY );
    if (fd == -1){
        this->setFail();
        this->setErrorStr( "Falha ao abrir: " + (std::string)dispositivo + ". " + (std::string)strerror(errno) );

        return -1;
    }

    memset( &terminalOptions, 0, sizeof( struct termios ) );        // Cleaning up the structure
    cfmakeraw(&terminalOptions);                                    //

    //speed_t speed = 57600;

    tcsetattr(fileDescriptor,TCSANOW,&terminalOptions);
    cout<< tcgetattr(fileDescriptor,&terminalOptions)<<endl;

    cfsetspeed(&terminalOptions, 1);
    cout<< "boudrate: " << cfgetospeed(&terminalOptions) << endl;

    ret = ioctl( fd, TIOCSETD, &terminalOptions );  // Configuring the device
    if (ret == -1){
        this->setFail();
        this->setErrorStr( "Failed to failed to configure device: " + (std::string)dispositivo + ". " + (std::string)strerror(errno) );

        return -1;
    }

    return fd;
}

void Serial::setFail(){
    fail_ = true;
}

bool Serial::fail(){
    return fail_;
}

void Serial::setErrorStr(std::string errorString){
    errorString_ = errorString;
}

std::string Serial::getErrorStr(){
    return errorString_;
}

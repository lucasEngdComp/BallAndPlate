//
// Created by assert-latomia on 03/10/2019.
//
//#define _GNU_SOURCE
#include "ConexaoSerial.hpp"
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>    // POSIX terminal control definitions
//#include <sys/ioctl.h>
#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

// Constructors
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

    fd = open(dispositivo, O_RDWR | O_NOCTTY | O_NDELAY);

    if(fd == -1) {
        printf( "failed to open port\n" );
    }

    struct termios terminalOptions;

    if(!isatty(fd)) {

        cout << "ERRO NO DISPOSITIVO CONECTADO"<< endl ;

    }

    if(tcgetattr(fd, &terminalOptions) < 0){
        cout << "ERRO NA CONFG ATUAL DA SERIAL"<< endl ;
    }

    terminalOptions.c_iflag &= ~(IGNBRK | BRKINT | ICRNL | INLCR | PARMRK | INPCK | ISTRIP | IXON);

    terminalOptions.c_oflag &= ~(OCRNL | ONLCR | ONLRET | ONOCR | OFILL | OLCUC | OPOST);

    terminalOptions.c_lflag &= ~(ECHO | ECHONL | ICANON | IEXTEN | ISIG);

    terminalOptions.c_cflag &= ~(CSIZE | PARENB);

    terminalOptions.c_cflag |= CS8;

//    terminalOptions.c_cc[VMIN] = 0;         // 1 second timeout
//
//    terminalOptions.c_cc[VTIME] = 10;       //

//    if(cfsetispeed(&terminalOptions, B500000) < 0 || cfsetospeed(&terminalOptions, B500000) < 0) {
//        cout << "FALHA AO SETAR OS BAUDRATES" << endl;
//    }

    if(cfsetospeed(&terminalOptions, B500000) < 0) {
        cout << "FALHA AO SETAR OS BAUDRATES" << endl;
    }

    if(tcsetattr(fd, TCSAFLUSH, &terminalOptions) < 0) {
        cout << "FALHA- AO SETAR AO APLICAR AS CONFIGURAÇÕES" << endl;
    }

    if(tcgetattr(STDOUT_FILENO, &terminalOptions) < 0)
    {
        perror("stdin");
        return EXIT_FAILURE;
    }

    if(tcgetattr(STDOUT_FILENO, &terminalOptions) < 0)
    {
        perror("stdin");
        return EXIT_FAILURE;
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

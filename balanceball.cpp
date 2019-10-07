
#include "./camera/camera.hpp"
#include "ConecxaoSerial/ConexaoSerial.hpp"


#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>  // cv::Canny()

#define REFRESH_PERIOD  5      // In milliseconds
#define ESC_SC          27     // ESC scan code

#define NORMAL          0
#define SQUARE          1


using std::cout;
using std::cerr;
using std::endl;
using namespace cv;
int main(int argc, char* argv[])
{
    int mode = NORMAL;
    int x, y;
    size_t nFrames = 0;

    int64 t0 = cv::getTickCount();
    int64 processingTime = 0;

    Platform platform( "/dev/ttyUSB1", 9600 );
    Camera camera;

    if ( camera.fail() )
    {
            cerr << camera.getErrorStr() << endl;
            exit( EXIT_FAILURE );
    }
    switch( mode )
    {
        case NORMAL:{

            cout<<"Objeto encontrado";

            while ( true ){
                camera.atualiza(); // função que chama o método que cria a camera
//                    cout << endl;
//                    cout << "coordenada x: " << camera.getX() << endl;
//                    cout << "coordenada y: " << camera.getY() << endl;
                if ( cv::waitKey(REFRESH_PERIOD) == ESC_SC ) // esczão.
                {
                    break;
                }
                x = camera.getX();
                y = camera.getY();
                platform.setAngles(x,y); // escreve dois inteiros na serial
//                cout << "X: " << x << endl;
//                cout << "Y: " << y << endl;
//                cout << endl;
                nFrames++;
                if (nFrames % 10 == 0){
                    const int N = 10;
                    int64 t1 = cv::getTickCount();
                    cout << "Frames captured: " << cv::format("%5lld", (long long int)nFrames)
                         << "    Average FPS: " << cv::format("%9.1f", (double)getTickFrequency() * N / (t1 - t0))
                         << "    Average time per frame: " << cv::format("%9.2f ms", (double)(t1 - t0) * 1000.0f / (N * getTickFrequency()))
                         << "    Average processing time: " << cv::format("%9.2f ms", (double)(processingTime) * 1000.0f / (N * getTickFrequency()))
                         << std::endl;
                    t0 = t1;
                }
            }
                break;
            }
    }
    exit( EXIT_SUCCESS );

}

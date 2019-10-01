
#include "./camera/camera.hpp"

//cv2.namedWindow("Frame", cv2.WINDOW_FREERATIO)#redimencionamento
#include <iostream>
#include <cmath>
#define REFRESH_PERIOD  5      // In milliseconds
#define ESC_SC          27     // ESC scan code

#define NORMAL          0
#define SQUARE          1


using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char* argv[])
{
    int mode = NORMAL;
    Camera camera;
    if ( camera.fail() )
    {
            cerr << camera.getErrorStr() << endl;
            exit( EXIT_FAILURE );
    }
    switch( mode )
    {
        case NORMAL:
            {   cout<<"Objeto encontrado";
                while ( true )
            {
                    camera.atualiza(); // função que chama o método que cria a camera
                    cout << endl;
                    cout << "coordenada x: " << camera.getX() << endl;
                    cout << "coordenada y: " << camera.getY() << endl;
                    if ( cv::waitKey(REFRESH_PERIOD) == ESC_SC ) // esczão.
                    {
                        break;
                    }
            }
                break;
            }
    }
    exit( EXIT_SUCCESS );

}

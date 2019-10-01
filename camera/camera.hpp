#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <string>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
 // classe Camera // setando os (des)construtores, setan
class Camera
{

public:


        Camera(); // construtor da camera
        ~Camera(); // desconstrutor da camera

        void atualiza(); // atualização  da camera

        int getX(); // pega os valores de X
        int getY(); // pega os valores de y

        bool fail();
        std::string getErrorStr();

        // Constants for bluer ball // 98,109,20 até  112,255,255
        static const int lowH_       = 98;
        static const int highH_      = 112;

        static const int lowS_       = 109;
        static const int highS_      = 255;

        static const int lowV_       = 20;
        static const int highV_      = 255;
        // fim das constantes que regem as cores da bola

        static const int ballArea_    = 300000;  // área aproximada da bola ( medida real da bola )
        static const int ballRadius_  = 36;      // tamanho que o quadrado irá fazer na bola.


private:
        void setFail(); // METODO PARA VERIFICAÇÃO DE LEITURA DE CAMERA
        void setErrorStr( std::string errorString ); //  SETAR O ERRO, CASO HAJA UM.

        int x_;                         // valor x
        int y_;                         // valor y

        cv::VideoCapture camera_;       // Inicializador da camera

        cv::Mat image;                     // novo frame
        cv::Mat imagemHSV;                // bgr -> converter para HSV
        cv::Mat imagemBinarizada;        // Thresholded HSV image
        cv::Mat imgSquare_;             // circulo num quadrado

        cv::Moments objMoments_;        // momentos da imagem.
        double  objMoment01_;           // responsável por Y
        double  objMoment10_;           // Responsável por  x
        double  objArea_;               // numeros de pixels do objeto.

        bool fail_;                     // verificação .. retorna true ou false
        std::string errorString_;
};

#endif // CAMERA_HPP
#include "camera.hpp"

// Construtor (usado para setar os valores padrões, caso não  seja passado nada.
Camera::Camera() : x_(0), y_(0), camera_(0), image(), imagemHSV(), imagemBinarizada(), objMoments_(), objMoment01_(0.0), objMoment10_(0.0), objArea_(0.0), fail_(false), errorString_("")
{
        if ( !camera_.isOpened() )  // If not success, exit program
        {
                this->setFail();
                this->setErrorStr( "Failed to open camera." );
        }
        cv::Mat imgTmp;
        camera_.read( imgTmp );
        imgSquare_ = cv::Mat::zeros( imgTmp.size(), CV_8UC3 ); // criando uma matriz de 0's e 1's // quando a camera for inicializada, ela pega o tamanho o input da camera e transforma em 0 1
}
// desconstrutor( para destruir a classe/objeto camera.)
Camera::~Camera()
{
        x_ = -1;
        y_ = -1;
        camera_.~VideoCapture();
        image.~Mat();
        imagemHSV.~Mat();
        imagemBinarizada.~Mat();
        objMoments_.~Moments();
        objMoment01_ = -1;
        objMoment10_ = -1;
        objArea_     = -1;
        fail_ = true;
        errorString_ = "";
}

void Camera::atualiza(){       int ret = 0;
        ret = camera_.read(image ); // Lendo um novo frame da camera.
        // verificação na leitura da camera
        if ( !ret )
        {
                this->setFail();
                this->setErrorStr( "Falha ao ler um frame da camera" );

                return;
        }

        cv::cvtColor(image, imagemHSV, cv::COLOR_BGR2HSV ); // Converting the captured frame from BGR to HSV
        cv::inRange(imagemHSV,                                     // Thresholding the image
                     cv::Scalar(lowH_,  lowS_,  lowV_),
                    cv::Scalar(highH_, highS_, highV_),
                    imagemBinarizada );

        // calculando os momentos da imagem binarizada.
        objMoments_ = cv::moments(imagemBinarizada );
        objMoment01_ = objMoments_.m01;
        objMoment10_ = objMoments_.m10;
        objArea_     = objMoments_.m00;

        if (objArea_ > ballArea_){
                x_ = objMoment10_ / objArea_;
                y_ = objMoment01_ / objArea_;
                // Fazendo um quadrado na bola, escolhendo as cores que serão utilizadas para fazer.
                line( imgSquare_, cv::Point(x_ - ballRadius_, y_ + ballRadius_),        // Linha vertical
                                  cv::Point(x_ - ballRadius_, y_ - ballRadius_),
                                  cv::Scalar(198,200,240), 2);

                line( imgSquare_, cv::Point(x_ + ballRadius_, y_ + ballRadius_),   // Linha vertical
                                  cv::Point(x_ + ballRadius_, y_ - ballRadius_),
                                  cv::Scalar(198,200,240), 2);

                line( imgSquare_, cv::Point(x_ - ballRadius_, y_ + ballRadius_),        // Linha horizontal
                                  cv::Point(x_ + ballRadius_, y_ + ballRadius_),
                                  cv::Scalar(198,200,240), 2);

                line( imgSquare_, cv::Point(x_ - ballRadius_, y_ - ballRadius_), //Linha horizontal
                                  cv::Point(x_ + ballRadius_, y_ - ballRadius_),
                                  cv::Scalar(198,200,240), 2);
        }

        /* função imshow , serve para mostrar as imagens, no caso a imagem real e a imagem binarizada.
         */
        cv::imshow("imagem binarizada", imagemBinarizada ); // Mostrando a imagem "binarizada"

        image = image + imgSquare_;
        cv::imshow("Original", image ); // Mostrando a imagem original

        imgSquare_ = cv::Mat::zeros( imgSquare_.size(), CV_8UC3 ); // Clearing the imgSquare_

}
// métodos para pegar X e Y
int Camera::getX()
{
        return x_;
}

int Camera::getY()
{
        return y_;
}
// verificações se a camera está aberta.
void Camera::setFail()
{
        fail_ = true;
}
bool Camera::fail()
{
        return fail_;
}
void Camera::setErrorStr( std::string errorString )
{
        errorString_ = errorString;
}
std::string Camera::getErrorStr()
{
        return errorString_;
}
// fim das verificações
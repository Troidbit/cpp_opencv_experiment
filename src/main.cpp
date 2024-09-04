#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
 
int main( int argc, char* argv[]){
    const std::string window_name1 = "invert";
    const std::string window_name2 = "normal";

    VideoCapture cap(0);

    if (!cap.isOpened()) {
        std::cerr << "Could not open camera." << std::endl;
        return -1;
    }

    Mat image1;
    cap >> image1;

    bitwise_not(image1,image1);

    imshow(window_name1,image1);
    moveWindow(window_name1,0,200);

    waitKey(0);

    cap.release();
    destroyAllWindows();
    return 0;
}
#include "imageclass.h"
#include "mathcalculate.h"
#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

ImageMap::ImageMap(const std::string& filename) {//init.
    pixels = imread(filename, cv::IMREAD_COLOR);
    outFileName = createOutFilename(filename);
}
    std::string ImageMap::createOutFilename(const std::string& input_filename) {
        auto foo = input_filename.find_last_of('.');

        std::string output_filename = "";
        if(foo != std::string::npos) { //for safety when there is no dot
                    output_filename = input_filename.substr(0, foo) +
                            "_new" + input_filename.substr(foo, input_filename.length());//Adding new before dot
            }
        else {
            output_filename = input_filename+"_new";
        }
        return output_filename;
}

void ImageMap::show() {
    if(pixels.empty()){
        std::cout<<"File not exist\n";
    }
    else{
        cv::imshow("Your's target", pixels);
        int k = cv::waitKey(0); // Wait for a keystroke in the window

    }
}

void ImageMap::drawCircle(int radius, int size_line) {
    int center_x = pixels.rows/2;
    int center_y = pixels.cols/2;

    cv::circle(pixels,cv::Point (center_x,center_y),radius,cv::Scalar (0, 255, 0), size_line);
}

void ImageMap::sizeImage(){
    int up_width = mmToPx(550); //in mm
    int up_height = mmToPx(550);//in mm
    cv::Mat resized_up;
    //resize up
    cv::resize(pixels, pixels, cv::Size(up_width, up_height), cv::INTER_LINEAR);
}
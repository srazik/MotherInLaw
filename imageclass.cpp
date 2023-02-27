#include "imageclass.h"
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include "mathcalculate.h"
#include "opencv2/objdetect.hpp"

ImageMap::ImageMap(const std::string& filename) {  // init.
    if (fopen(filename.c_str(), "r")) {            // do only when file is exist and we can open
        pixels = imread(filename, cv::IMREAD_COLOR);
        outFileName = createOutFilename(filename);
    }
}
std::string ImageMap::createOutFilename(const std::string& inputFilename) {
    auto foo = inputFilename.find_last_of('.');

    std::string outputFilename = "";  // Initialisation only
    if (foo != std::string::npos) {   // for safety when there is no dot
        outputFilename = inputFilename.substr(0, foo) +
                         "_target" + inputFilename.substr(foo, inputFilename.length());  // Adding new before dot
    } else {
        outputFilename = inputFilename + "_target";
    }
    return outputFilename;
}

void ImageMap::show() {
    if (pixels.empty()) {  // checking if file is empty
        std::cout << "File not exist\n";
    } else {
        cv::imshow("Your's target", pixels);
        cv::waitKey(0);  // Wait for a keystroke in the window
    }
}

void ImageMap::saveImage() {
    if (pixels.empty()) {
        std::cout << "File not exist\n";   // checking gi file is empty
    } else {                               // for not empty
        cv::imwrite(outFileName, pixels);  // writing image
        std::cout << "File created!\n";
    }
}

void ImageMap::drawCircle(int radius, int sizeLine) {
    int center_x = pixels.rows / 2;  // On half of raws & cols
    int center_y = pixels.cols / 2;

    cv::circle(pixels, cv::Point(center_x, center_y), radius, cv::Scalar(0, 0, 255), sizeLine);
}

void ImageMap::sizeImage(int width, int height) {
    int up_width = mmToPx(width);    // in mm
    int up_height = mmToPx(height);  // in mm
    // resize up
    cv::resize(pixels, pixels, cv::Size(up_width, up_height), cv::INTER_LINEAR);
}

void ImageMap::humanDetect() {
    // Look face on picture
}

cv::Mat ImageMap::faceDetection(const std::string& filename) {
    int x;  // Knowlage of point x on picture
    int y;  // Knowlage of point y on picture
    int sizeWidth = 0;
    int sizeHeight = 0;
    cv::CascadeClassifier faceClassifier;  // adding clasifiler
    faceClassifier.load(filename);         // remember a good path for xml file - without it won't work

    cv::Mat gray;
    cv::cvtColor(pixels, gray, cv::COLOR_BGR2GRAY);  // creation of grey picture

    // Look face on gray picture
    std::vector<cv::Rect> faces;
    faceClassifier.detectMultiScale(gray, faces);

    cv::Mat imageFaces = pixels.clone();  // setting image as grey
    for (cv::Rect face : faces) {
        if (face.width >= cv::max(face.width, sizeWidth)) {
            x = std::max(face.x - face.width / 8, 0);   // To avoid value <0
            y = std::max(face.y - face.height / 8, 0);  // To avoid value < 0
            sizeWidth = face.width;
            sizeHeight = face.height;

            // cv::Rect roi(x, y, std::min(face.width + face.width / 8, face.height + face.height / 8), std::min(face.width + face.width / 8, face.height + face.height / 8));
            // imageFaces = imageFaces(roi);  // Cutting image
            //  circle(imageFaces, cv::Point(x, y), 100, cv::Scalar(0, 0, 255), 10, cv::LINE_AA);
            //  rectangle(imageFaces, face, cv::Scalar(255, 0, 0), -1);  //-1 means that it
            //   will be filled
        }
    }
    if (sizeWidth > 0) {
        cv::Rect roi(x, y, sizeWidth + sizeWidth / 8, sizeHeight + sizeWidth / 8);
        imageFaces = imageFaces(roi);
    } /*else {
        cv::Mat blueImage(800, 800, CV_8UC1, cv::Scalar(0, 0, 0));
        imageFaces = blueImage.clone();

    }*/
    return imageFaces;
}

cv::Mat ImageMap::findContures() {
    cv::Mat gray;
    cv::cvtColor(pixels, gray, cv::COLOR_BGR2GRAY);  // creation of grey picture

    // making threshold for pictures
    cv::Mat thresh;
    cv::threshold(gray, thresh, 150, 255, cv::THRESH_BINARY);
    // detect the contours on the binary image using cv2.CHAIN_APPROX_NONE
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    findContours(thresh, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_NONE);

    // draw contures on image
    cv::Mat pixelsCopy = pixels.clone();
    cv::drawContours(pixelsCopy, contours, -1, cv::Scalar(0, 255, 0), 2);

    return pixelsCopy;
}

cv::Mat ImageMap::writeNumber(const std::string & Number, int pozX, int pozY){

    cv::Mat dupa;
    //Font and parameter to them (to be checked
    int font = cv::FONT_HERSHEY_SIMPLEX;
    double fontScale = 4;
    int thickness = 5;
    int baseline = 0;
    //checking size of text to be sure that will be on position that we want
    cv::Size textSize = cv::getTextSize(Number, font, fontScale, thickness, &baseline);
    // Position the text in the center of the image
    cv::Point textOrg((2*pozX - textSize.width)/2, (2*pozY+textSize.height)/2);
    cv::putText(pixels,Number,textOrg,font,fontScale, cv::Scalar(255,255,255),thickness);

    return dupa;
}
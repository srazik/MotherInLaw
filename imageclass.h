#ifndef MOTHERINLAW_FILENAME_H
#define MOTHERINLAW_FILENAME_H
#include <iostream>
#include <opencv2/core.hpp>

class ImageMap {
public:
    ImageMap(const std::string& filename);
    cv::Mat pixels;                                      // Our picture
    std::string outFileName;                             // Filename that we save
    void show();                                         // showing result of file
    void saveImage();                                    // Saving image to file using outFileName
    void drawCircle(int radius, int sizeLine);           // drawing a circles from the middle of it
    void sizeImage(int width, int height);               // at begining without parameters after we add size of targets
    void humanDetect();                                  // For detection contours of human
    cv::Mat faceDetection(const std::string& filename);  // Return MAt with detected face on orginal picture
    cv::Mat findContures();

//private:
    static std::string createOutFilename(const std::string& inputFilename);  // remember it was privat temporary
};

#endif  // MOTHERINLAW_FILENAME_H

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "imageclass.h"
#include "mathcalculate.h"


int main()
{
   ImageMap my_image("/home/razikszy/CLionProjects/MotherInLaw/dupa.jpg");
   my_image.sizeImage(150,150);//sizing image -
   //my_image.drawCircle(mmToPx(100), 3); //size of 100 mm
   //my_image.show();
   auto dupa = ImageMap::createOutFilename("dupa");
    my_image.humanDetect();

  //  std::string image_path = samples::findFile("/home/razikszy/CLionProjects/MotherInLaw/starry_night.jpg");
  //  Mat img = imread(image_path, IMREAD_COLOR);
  //  if(img.empty())
  //  {
  //      std::cout << "Could not read the image: " << image_path << std::endl;
  //      return 1;
  //  }
  //  imshow("Display window", img);
  //  int k = waitKey(0); // Wait for a keystroke in the window
  //  if(k == 's')
  //  {
  //      imwrite("starry_night.png", img);
  //  }
    return 0;
}
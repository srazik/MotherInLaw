#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "filename.h"


int main()
{
   ImageMap my_image("/home/razikszy/CLionProjects/MotherInLaw/dupa.jpg");
   my_image.drawCircle(15);
   my_image.show();
   auto dupa = ImageMap::create_out_filename("dupa");


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
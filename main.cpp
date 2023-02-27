#include <iostream>
#include "imageclass.h"
#include "mathcalculate.h"

int main() {
    ImageMap my_image("../dupa.jpg");
    if (my_image.pixels.empty()) {
        std::cout << "There is no file!\n";
    } else {
        // my_image.sizeImage(1500, 1500);  // sizing image -
        //  my_image.drawCircle(mmToPx(100), 30);       // size of 100 mm
        //   my_image.humanDetect();
        my_image.pixels = my_image.faceDetection("/home/razikszy/CLionProjects/MotherInLaw/haarcascade_frontalface_default.xml");
        my_image.sizeImage(600, 600);
        for (int i = 0; i < 10; i++) {
            my_image.drawCircle(mmToPx(50 + 25 * i), mmToPx(1));
            if (i!=0) {
                        my_image.writeNumber(std::to_string(10 - i), mmToPx(337) + mmToPx(25 * i), mmToPx(300));
                my_image.writeNumber(std::to_string(10 - i), mmToPx(300), mmToPx(263) - mmToPx(25 * i));
                my_image.writeNumber(std::to_string(10 - i), mmToPx(263) - mmToPx(25 * i), mmToPx(300));
                my_image.writeNumber(std::to_string(10 - i), mmToPx(300),mmToPx(337) + mmToPx(25 * i));
            }
        }
        my_image.writeNumber("X", mmToPx(300), mmToPx(300));

//        my_image.show();
        my_image.saveImage();
    }

    return 0;
}
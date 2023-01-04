#include "mathcalculate.h"
#include <cmath>

int convertValue(const int size, const double converter) {
    if (size > 0) {
        return int(round(size * converter));
    } else {
        return 0;
    }
}

int pxToMm(const int size_px) {
    double converter = 0.264583;
    return convertValue(size_px, converter);
}

int mmToPx(const int size_mm) {
    double converter = 3.779528;
    return convertValue(size_mm, converter);
}
#ifndef MOTHERINLAW_MATHCALCULATE_H
#define MOTHERINLAW_MATHCALCULATE_H

int pxToMm(const int size_px);  // changing px to mm using converter 1px is 0.264583mm
int mmToPx(const int size_mm);  // changing mm to px using converter 1mm is 3.779528px
int convertValue(const int size, const double converter);

#endif  // MOTHERINLAW_MATHCALCULATE_H
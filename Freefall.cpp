#include <stdio.h>
#include <math.h>

int main(void) {
  double time, height, mps, fts, mph;
  printf("Enter the initial height of the object in meters: ");
  scanf("%lf", &height);
  printf("\n");
  time = sqrt((2*height)/9.81);
  printf("The object took %.2lf seconds to fall.\n", time);
  mps = 9.81 * time;
  fts = mps * 3.28084;
  mph = mps * 2.23694;
  printf("The velocity of the object at impact was: %.1lf m/sec\n %.1lf ft/sec\n %.1lf mph", mps, fts, mph);





  return 0;
}
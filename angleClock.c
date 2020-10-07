#include <math.h>

double angleClock(int hour, int minutes)
{
  double angle;
  double hourMod;

  hourMod = (double) (hour % 12);
  angle = 5.0 * fabs(6.0 * hourMod - 1.1 * (double) minutes);
  if (angle <= 180.0) {
    return angle;
  } else {
    return 360.0 - angle;
  }
}

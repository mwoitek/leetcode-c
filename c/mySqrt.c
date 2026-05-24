#include <limits.h>

int mySqrt(int x)
{
    if (x == 0) {
        return 0;
    }

    unsigned long left = 0;
    unsigned long middle;
    unsigned long right = ULONG_MAX;
    unsigned long temp;
    unsigned long xUlong = (unsigned long) x;

    while (left <= right) {
        middle = left + (right - left) / 2;
        temp = xUlong / middle;
        if (middle < temp) {
            left = middle + 1;
        } else if (middle > temp) {
            right = middle - 1;
        } else {
            return (int) middle;
        }
    }
    return (int) right;
}

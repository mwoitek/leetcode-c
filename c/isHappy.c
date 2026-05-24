#include <math.h>

#define MAX_ITER 80

int sum_digits(int n)
{
    int sum = 0;

    while (n) {
        sum += (int) pow((double) (n % 10), 2.0);
        n /= 10;
    }
    return sum;
}

bool isHappy(int n)
{
    int iter = 0;
    bool stop = false;

    while (!stop && (iter <= MAX_ITER)) {
        n = sum_digits(n);
        iter++;
        stop = (n == 1);
    }
    return stop;
}

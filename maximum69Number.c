#include <math.h>

int maximum69Number(int num)
{
    char digits_str[6];
    int i, num_digits;
    int temp = num;

    sprintf(digits_str, "%d", num);
    num_digits = strlen(digits_str);

    int digits[num_digits];
    int N1 = num_digits - 1;

    for (i = N1; i >= 0; i--) {
        digits[i] = temp % 10;
        temp /= 10;
    }
    i = 0;
    while ((i < num_digits) && (digits[i] == 9)) {
        i++;
    }
    if (i == num_digits) {
        return num;
    }
    digits[i] = 9;
    for (i = N1; i >= 0; i--) {
        temp += digits[i] * (int) pow(10.0, (double) (N1 - i));
    }
    return temp;
}

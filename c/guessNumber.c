int guess(int num);

int guessNumber(int n)
{
    int test;
    unsigned long left = 1;
    unsigned long middle;
    unsigned long right = (unsigned long) n;

    while (left <= right) {
        middle = left + (right - left) / 2;
        test = guess(middle);
        if (test == 1) {
            left = middle + 1;
        } else if (test == -1) {
            right = middle - 1;
        } else {
            break;
        }
    }
    return (int) middle;
}

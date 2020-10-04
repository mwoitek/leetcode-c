bool isPowerOfFour(int num)
{
    if (num < 1) {
        return false;
    }
    while (!(num % 4)) {
        num /= 4;
    }
    return !(num / 4) && (num % 4 == 1);
}

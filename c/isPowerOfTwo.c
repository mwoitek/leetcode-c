bool isPowerOfTwo(int n)
{
    if (n < 1) {
        return false;
    }
    while (!(n % 2)) {
        n /= 2;
    }
    return !(n / 2);
}

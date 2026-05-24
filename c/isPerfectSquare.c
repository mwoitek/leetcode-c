bool isPerfectSquare(int num)
{
    if (num < 0) {
        return false;
    } else if (!num) {
        return true;
    }

    double dnum = (double) num;
    unsigned int i = 1;

    while (i < dnum / i) {
        i += 1;
    }
    return (i == num / i);
}

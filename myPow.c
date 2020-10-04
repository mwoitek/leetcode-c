double helper(double x, long n)
{
    if (!n) {
        return 1.0;
    } else if (!(n % 2)) {
        return helper(x * x, n / 2);
    } else {
        return x * helper(x * x, (n - 1) / 2);
    }
}

double myPow(double x, long n)
{
    if (n >= 0) {
        return helper(x, n);
    } else {
        return 1.0 / helper(x, -n);
    }
}

int subtractProductAndSum(int n)
{
    int digit, prod = 1, sum = 0;

    while (n) {
        digit = n % 10;
        prod *= digit;
        sum += digit;
        n /= 10;
    }
    return prod - sum;
}

long powmod(long a, long e, long n)
{
    long accum = 1, apow = a, x = e;

    while (x) {
        if (x & 0x01) {
            accum = (accum * apow) % n;
        }
        x >>= 1;
        apow = (apow * apow) % n;
    }
    return accum;
}

int smallestRepunitDivByK(int K)
{
    if (!(K % 2) || !(K % 5)) {
        return -1;
    }
    if (K == 1) {
        return 1;
    }

    int num_digits = 1, remain = 1;

    while (remain) {
        remain += (int) powmod(10, (long) num_digits, (long) K);
        remain %= K;
        num_digits++;
    }
    return num_digits;
}

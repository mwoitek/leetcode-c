int tribonacci(int n)
{
    int i, seq[38];

    seq[0] = 0;
    seq[1] = 1;
    seq[2] = 1;
    if (n >= 3) {
        for (i = 3; i <= n; i++) {
            seq[i] = seq[i - 3] + seq[i - 2] + seq[i - 1];
        }
    }
    return seq[n];
}

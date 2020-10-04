int fib(int N)
{
    if (N < 2) {
        return N;
    } else {
        return fib(N - 2) + fib(N - 1);
    }
}

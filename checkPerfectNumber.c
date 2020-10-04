bool checkPerfectNumber(int num)
{
    if (num < 2) {
        return false;
    }

    int i, sum_div = 1, temp;

    for (i = 2; i * i <= num; i++) {
        if (!(num % i)) {
            temp = num / i;
            if (i != temp) {
                sum_div += i + temp;
            } else {
                sum_div += i;
            }
        }
    }
    return num == sum_div;
}

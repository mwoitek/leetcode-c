int divisors[3] = {2, 3, 5};

int number_that_divides(int num)
{
    int i = 0;

    while ((i < 3) && (num % divisors[i] != 0)) {
        i++;
    }
    if (i == 3) {
        return -1;
    } else {
        return divisors[i];
    }
}

bool isUgly(int num)
{
    if (num < 1) {
        return false;
    }

    int temp;

    while (num != 1) {
        temp = number_that_divides(num);
        if (temp == -1) {
            return false;
        } else {
            num /= temp;
        }
    }
    return true;
}

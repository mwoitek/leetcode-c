void one_step(int* num)
{
    if (!(*num % 2)) {
        *num /= 2;
    } else {
        *num -= 1;
    }
}

int numberOfSteps(int num)
{
    int steps = 0;

    while (num) {
        one_step(&num);
        steps += 1;
    }
    return steps;
}

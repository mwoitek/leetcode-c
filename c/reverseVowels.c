#include <math.h>

char vowels[11] = "AEIOUaeiou";

bool is_vowel(char c)
{
    int left = 0, middle, right = 9;
    char temp;

    while (left <= right) {
        middle = (int) floor((left + right) / 2.0);
        temp = vowels[middle];
        if (temp < c) {
            left = middle + 1;
        } else if (temp > c) {
            right = middle - 1;
        } else {
            return true;
        }
    }
    return false;
}

void swap(char* a, char* b)
{
    char temp = *a;

    *a = *b;
    *b = temp;
}

char* reverseVowels(char* s)
{
    int left = 0, right;
    bool stop;

    right = strlen(s) - 1;
    stop = left > right;
    while (!stop) {
        while (!stop && !is_vowel(s[left])) {
            left++;
            stop = left > right;
        }
        while (!stop && !is_vowel(s[right])) {
            right--;
            stop = left > right;
        }
        if (!stop) {
            swap(&s[left], &s[right]);
            left++;
            right--;
            stop = left > right;
        }
    }
    return s;
}

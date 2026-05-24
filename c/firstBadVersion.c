#include <stdbool.h>

/* The API isBadVersion is defined for you. */
bool isBadVersion(int version);

int firstBadVersion(int n)
{
    int first = n;
    int left = 1;
    int middle;
    int right = n;

    while (left <= right) {
        middle = left + (right - left) / 2;
        if (isBadVersion(middle)) {
            first = middle;
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    return first;
}

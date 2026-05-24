#include <string.h>

int max(int x, int y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

int maxLengthBetweenEqualCharacters(char *s) {
    char letter;
    char *next;
    int maxLength = -1;
    unsigned int i, sLength = strlen(s);

    for (i = 0; i < sLength - 1; i++) {
        letter = s[i];
        next = strchr(s + i + 1, letter);
        while (next != NULL) {
            maxLength = max(maxLength, strlen(s + i) - strlen(next) - 1);
            next = strchr(next + 1, letter);
        }
    }
    return maxLength;
}

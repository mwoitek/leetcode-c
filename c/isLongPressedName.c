#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct lc {
    char letter;
    unsigned int count;
};

struct cl {
    struct lc *counts;
    unsigned int size;
};

struct cl computeCounts(char *s) {
    char letter;
    unsigned int count;
    unsigned int i = 0;
    unsigned int j;
    unsigned int k = 0;
    unsigned int len = strlen(s);
    struct cl countsList;
    struct lc *counts = (struct lc *)malloc(len * sizeof(struct lc));

    while (i < len) {
        letter = s[i];
        count = 1;
        j = i + 1;
        while ((j < len) && (s[j] == letter)) {
            count++;
            j++;
        }
        counts[k].letter = letter;
        counts[k].count = count;
        k++;
        i = j;
    }
    counts = (struct lc *)realloc(counts, k * sizeof(struct lc));
    countsList.counts = counts;
    countsList.size = k;
    return countsList;
}

bool isLongPressedName(char *name, char *typed) {
    struct cl clName = computeCounts(name);
    struct cl clTyped = computeCounts(typed);
    unsigned int size = clName.size;

    if (clTyped.size != size) {
        return false;
    }

    bool answer = true;
    bool testLetter;
    bool testCount;
    unsigned int i;

    for (i = 0; i < size; i++) {
        testLetter = clName.counts[i].letter != clTyped.counts[i].letter;
        testCount = clName.counts[i].count > clTyped.counts[i].count;
        if (testLetter || testCount) {
            answer = false;
            break;
        }
    }
    return answer;
}

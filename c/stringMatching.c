/* Note: The returned array must be malloced, assume caller calls free(). */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

unsigned int* computeLengths(char** words, int wordsSize)
{
    int i;
    unsigned int* lengths = (unsigned int*) malloc(wordsSize * sizeof(unsigned int));

    for (i = 0; i < wordsSize; i++) {
        lengths[i] = strlen(words[i]);
    }
    return lengths;
}

bool isSubstring(char* word1, unsigned int length1, char* word2, unsigned int length2)
{
    if (length1 >= length2) {
        return false;
    }

    char firstLetter = word1[0];
    char* stringFromFirst = strchr(word2, firstLetter);
    while ((stringFromFirst != NULL) && (strlen(stringFromFirst) >= length1)) {
        if (!memcmp(word1, stringFromFirst, length1 * sizeof(char))) {
            return true;
        } else {
            stringFromFirst = strchr(stringFromFirst + 1, firstLetter);
        }
    }
    return false;
}

char** stringMatching(char** words, int wordsSize, int* returnSize)
{
    char* word;
    char** answer = (char**) malloc(wordsSize * sizeof(char*));
    int i;
    int j;
    unsigned int length;
    unsigned int* lengths = computeLengths(words, wordsSize);

    *returnSize = 0;
    for (i = 0; i < wordsSize; i++) {
        word = words[i];
        length = lengths[i];
        for (j = 0; j < wordsSize; j++) {
            if (i == j) {
                continue;
            }
            if (isSubstring(word, length, words[j], lengths[j])) {
                answer[*returnSize] = word;
                *returnSize += 1;
                break;
            }
        }
    }
    answer = (char**) realloc(answer, *returnSize * sizeof(char*));
    return answer;
}

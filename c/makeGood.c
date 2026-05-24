#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char* makeBetter(char* oldString, int oldLength, int* newLength)
{
    char c1;
    char c2;
    int* charsToKeep;
    int i;
    int j;
    char* newString;

    charsToKeep = (int*) malloc(oldLength * sizeof(int));
    i = 0;
    *newLength = oldLength;
    while (i < oldLength - 1) {
        j = i + 1;
        c1 = oldString[i];
        c2 = oldString[j];
        if ((tolower(c1) == tolower(c2)) && ((islower(c1) && isupper(c2)) || (isupper(c1) && islower(c2)))) {
            charsToKeep[i] = 0;
            charsToKeep[j] = 0;
            i += 2;
            *newLength -= 2;
        } else {
            charsToKeep[i] = 1;
            charsToKeep[j] = 1;
            i++;
        }
    }

    j = 0;
    newString = (char*) malloc((*newLength + 1) * sizeof(char));
    for (i = 0; i < oldLength; i++) {
        if (charsToKeep[i]) {
            newString[j] = oldString[i];
            j++;
        }
    }
    free(charsToKeep);
    newString[j] = '\0';
    return newString;
}

char* makeGood(char* s)
{
    char* oldString;
    int oldLength;
    char* newString;
    int newLength;

    oldString = s;
    oldLength = strlen(oldString);
    newString = makeBetter(oldString, oldLength, &newLength);
    do {
        oldString = newString;
        oldLength = newLength;
        newString = makeBetter(oldString, oldLength, &newLength);
    } while (oldLength > newLength);
    return newString;
}

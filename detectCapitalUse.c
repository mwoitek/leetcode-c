#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* convertToLower(const char* word, const unsigned int length)
{
    char* newString = (char*) malloc((length + 1) * sizeof(char));
    unsigned int i;

    for (i = 0; i < length; i++) { newString[i] = tolower(word[i]); }
    newString[length] = '\0';
    return newString;
}

char* convertToUpper(const char* word, const unsigned int length)
{
    char* newString = (char*) malloc((length + 1) * sizeof(char));
    unsigned int i;

    for (i = 0; i < length; i++) { newString[i] = toupper(word[i]); }
    newString[length] = '\0';
    return newString;
}

bool detectCapitalUse(char* word)
{
    const unsigned int length = strlen(word);
    if (length < 2) { return true; }
    if (!strcmp(word, convertToLower(word, length))) { return true; }
    if (!strcmp(word, convertToUpper(word, length))) { return true; }

    bool answer = true;
    unsigned int i;
    if (islower(word[0])) { answer = false; }
    else {
        for (i = 1; i < length; i++) {
            if (isupper(word[i])) {
                answer = false;
                break;
            }
        }
    }
    return answer;
}

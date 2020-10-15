#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char* toLowerCase(char* str)
{
    char* newStr;
    unsigned short i;
    unsigned short length;

    length = strlen(str);
    newStr = (char*) malloc((length + 1) * sizeof(char));
    for (i = 0; i < length; i++) {
        newStr[i] = isupper(str[i]) ? (char) (32 + (unsigned short) str[i]) : str[i];
    }
    newStr[length] = '\0';
    return newStr;
}

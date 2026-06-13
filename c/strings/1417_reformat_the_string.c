#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reformat(char* s)
{
  int num_digits = 0;
  int num_letters = 0;
  size_t len = strlen(s);

  for (size_t i = 0; i < len; i++) {
    if (isdigit(s[i]))
      num_digits++;
    else
      num_letters++;
  }

  if (abs(num_digits - num_letters) > 1) return "";

  char* out = malloc(len + 1);
  out[len] = '\0';

  size_t j = 0;  // digits
  size_t k = 0;  // letters
  if (num_digits < num_letters)
    j++;
  else
    k++;

  for (size_t i = 0; i < len; i++) {
    char c = s[i];
    if (isdigit(c)) {
      out[j] = c;
      j += 2;
    } else {
      out[k] = c;
      k += 2;
    }
  }

  return out;
}

int main(void)
{
  char* s1 = "a0b1c2";
  char* out1 = reformat(s1);
  printf("%s -> %s\n", s1, out1);
  if (strlen(out1)) free(out1);

  char* s2 = "leetcode";
  char* out2 = reformat(s2);
  printf("%s -> %s\n", s2, out2);
  if (strlen(out2)) free(out2);

  return 0;
}

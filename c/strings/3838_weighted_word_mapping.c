#include <string.h>

int computeWordWeight(char* word, int* weights)
{
  int weight = 0;
  for (size_t i = 0; i < strlen(word); i++) {
    int j = word[i] - 'a';
    weight += weights[j];
  }
  return weight;
}

char* mapWordWeights(char** words, int wordsSize, int* weights, int weightsSize)
{
  char* ans = malloc(wordsSize + 1);
  ans[wordsSize] = '\0';
  for (int i = 0; i < wordsSize; i++) {
    int wordWeight = computeWordWeight(words[i], weights);
    ans[i] = 'z' - wordWeight % 26;
  }
  return ans;
}

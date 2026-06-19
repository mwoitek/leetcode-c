int countDigits(int num, int digit)
{
  if (num == 0) return digit == 0;
  int cnt = 0;
  while (num > 0) {
    if (num % 10 == digit) cnt++;
    num /= 10;
  }
  return cnt;
}

int countDigitOccurrences(int* nums, int numsSize, int digit)
{
  int cnt = 0;
  for (int i = 0; i < numsSize; i++) {
    cnt += countDigits(nums[i], digit);
  }
  return cnt;
}

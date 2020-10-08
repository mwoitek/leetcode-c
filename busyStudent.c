int busyStudent(int* startTime, int startTimeSize, int* endTime, int endTimeSize, int queryTime)
{
  int count = 0, i;

  for (i = 0; i < startTimeSize; i++) {
    if ((queryTime >= startTime[i]) && (queryTime <= endTime[i])) {
      count++;
    }
  }
  return count;
}

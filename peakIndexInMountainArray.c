int peakIndexInMountainArray(int* arr, int arrSize)
{
    int left = 0;
    int middle;
    int right = arrSize - 1;
    int temp;

    while (left < right) {
        middle = left + (right - left) / 2;
        temp = middle + 1;
        if (arr[middle] > arr[temp]) {
            right = middle;
        } else {
            left = temp;
        }
    }
    return left;
}

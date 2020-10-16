#include <stdlib.h>

/* The following function has unnecessary arguments.
   However, since I'm not the one who defined it like this,
   I can't change this definition. */
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    if (!n) { return; }
    int i;
    if (!m) {
        for (i = 0; i < n; i++) {
            nums1[i] = nums2[i];
        }
        return;
    }

    int* copyNums1 = (int*) malloc(m * sizeof(int));
    for (i = 0; i < m; i++) {
        copyNums1[i] = nums1[i];
    }

    i = 0;
    int j = 0;
    int k = 0;
    while ((i < m) && (j < n)) {
        if (copyNums1[i] < nums2[j]) {
            nums1[k] = copyNums1[i];
            i++;
        } else {
            nums1[k] = nums2[j];
            j++;
        }
        k++;
    }
    while (i < m) {
        nums1[k] = copyNums1[i];
        i++;
        k++;
    }
    while (j < n) {
        nums1[k] = nums2[j];
        j++;
        k++;
    }

    free(copyNums1);
    return;
}

#include <limits.h>
#include <stdlib.h>

int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2)
        return 0;
    int minVal = INT_MAX, maxVal = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < minVal) minVal = nums[i];
        if (nums[i] > maxVal) maxVal = nums[i];
    }

    if (minVal == maxVal)
        return 0;

    int bucketSize = (maxVal - minVal) / (numsSize - 1);
    if (bucketSize == 0) bucketSize = 1;

    int bucketCount = (maxVal - minVal) / bucketSize + 1;

    int* bucketMin = (int*)malloc(bucketCount * sizeof(int));
    int* bucketMax = (int*)malloc(bucketCount * sizeof(int));
    char* bucketUsed = (char*)calloc(bucketCount, sizeof(char)); 

    for (int i = 0; i < bucketCount; i++) {
        bucketMin[i] = INT_MAX;
        bucketMax[i] = INT_MIN;
    }

    for (int i = 0; i < numsSize; i++) {
        int idx = (nums[i] - minVal) / bucketSize;
        if (!bucketUsed[idx]) bucketUsed[idx] = 1;
        if (nums[i] < bucketMin[idx]) bucketMin[idx] = nums[i];
        if (nums[i] > bucketMax[idx]) bucketMax[idx] = nums[i];
    }

    int maxGap = 0;
    int prevMax = minVal;

    for (int i = 0; i < bucketCount; i++) {
        if (!bucketUsed[i])
            continue;
        if (bucketMin[i] - prevMax > maxGap)
            maxGap = bucketMin[i] - prevMax;
        prevMax = bucketMax[i];
    }

    free(bucketMin);
    free(bucketMax);
    free(bucketUsed);

    return maxGap;
}

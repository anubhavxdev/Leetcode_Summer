#include <limits.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int maxSumDivThree(int* nums, int numsSize) {
    int sum = 0;
    int mod1[numsSize], mod2[numsSize];
    int count1 = 0, count2 = 0;

    for (int i = 0; i < numsSize; ++i) {
        sum += nums[i];
        if (nums[i] % 3 == 1)
            mod1[count1++] = nums[i];
        else if (nums[i] % 3 == 2)
            mod2[count2++] = nums[i];
    }

    if (sum % 3 == 0)
        return sum;

    qsort(mod1, count1, sizeof(int), cmp);
    qsort(mod2, count2, sizeof(int), cmp);

    int res = 0;
    if (sum % 3 == 1) {
        int remove1 = (count1 >= 1) ? mod1[0] : INT_MAX;
        int remove2 = (count2 >= 2) ? mod2[0] + mod2[1] : INT_MAX;
        res = sum - (remove1 < remove2 ? remove1 : remove2);
    } else { 
        int remove1 = (count2 >= 1) ? mod2[0] : INT_MAX;
        int remove2 = (count1 >= 2) ? mod1[0] + mod1[1] : INT_MAX;
        res = sum - (remove1 < remove2 ? remove1 : remove2);
    }

    return res;
}

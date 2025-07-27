int countHillValley(int* nums, int numsSize) {
    int clean[1000]; 
    int k = 0;
    clean[k++] = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            clean[k++] = nums[i];
        }
    }

    
    int count = 0;
    for (int i = 1; i < k - 1; i++) {
        if (clean[i] > clean[i - 1] && clean[i] > clean[i + 1]) {
            count++;  // Hill
        } else if (clean[i] < clean[i - 1] && clean[i] < clean[i + 1]) {
            count++;  // Valley
        }
    }

    return count;
}

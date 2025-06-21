void moveZeroes(int* nums, int numsSize) {
    int insertPos = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[insertPos++] = nums[i];
        }
    }

    while (insertPos < numsSize) {
        nums[insertPos++] = 0;
    }
}
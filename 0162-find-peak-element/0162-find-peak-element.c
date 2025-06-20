int findPeakElement(int* nums, int numsSize) {
    int peak = nums[0];
    int pos = 0;
    for(int i = 0; i<numsSize; i++){
        if(peak < nums[i]){
            peak = nums[i];
            pos = i;
        }
    }
    return pos;
}
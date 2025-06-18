int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int count = 0;
    int total = 0;
    for(int i = 0; i<numsSize; i++){
        if (nums[i] == 1){
            count++;
        }else{
            if(total < count){
                total = count;
            }
            count = 0;
        }
    }
    if(total < count){
            total = count;
        }
    return total;
}
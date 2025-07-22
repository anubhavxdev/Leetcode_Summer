

int maximumUniqueSubarray(int* nums, int numsSize) {
    int MAX_VAL = 10001;          
    int seen[MAX_VAL];           
    memset(seen, 0, sizeof(seen));

    int ans = 0, score = 0;
    int l = 0;

    for (int r = 0; r < numsSize; ++r) {
        while (seen[nums[r]]) {
            score -= nums[l];
            seen[nums[l]] = 0;
            l++;
        }
        score += nums[r];
        seen[nums[r]] = 1;
        if (score > ans)
            ans = score;
    }

    return ans;
}

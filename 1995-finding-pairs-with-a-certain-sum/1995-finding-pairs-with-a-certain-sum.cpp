class FindSumPairs {
public:
    vector<int> nums1, nums2;
    unordered_map<int, int> freq2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int x : nums2) {
            freq2[x]++;
        }
    }
    
    void add(int index, int val) {
        int oldVal = nums2[index];
        freq2[oldVal]--;       
        nums2[index] += val;
        freq2[nums2[index]]++; 
    }
    
    int count(int tot) {
        int res = 0;
        for (int x : nums1) {
            int need = tot - x;
            if (freq2.count(need)) {
                res += freq2[need];
            }
        }
        return res;
    }
};

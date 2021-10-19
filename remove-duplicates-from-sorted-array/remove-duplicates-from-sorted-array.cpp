class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto iter = unique(nums.begin(), nums.end());
        int k = iter - nums.begin();
        return k;
    }
};
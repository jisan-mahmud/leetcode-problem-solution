class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis(nums.size() + 1, INT_MAX);
        int ans = 0;

        for(int num : nums){
            int index = lower_bound(lis.begin(), lis.end(), num) - lis.begin();
            lis[index] = num;

            ans = max(ans, index+1);
        }

        return ans;
    }
};
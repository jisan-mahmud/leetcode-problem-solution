class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        int x = nums[0];
        int y = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++){
            int ans = max(y, x + nums[i]);
            x = y;
            y = ans;
        }

        return y;
        
    }
};
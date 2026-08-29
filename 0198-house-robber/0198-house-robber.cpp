class Solution {
public:
    int solve(vector<int>& nums, int n, int *dp){
        if(n < 0) return 0;

        if(dp[n] != -1) return dp[n];

        int rob = nums[n] + solve(nums, n - 2, dp);
        int notRod = solve(nums, n - 1, dp);

        return dp[n] = max(rob, notRod);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        memset(dp, -1, sizeof(dp));

        return solve(nums, n - 1, dp);
    }
};
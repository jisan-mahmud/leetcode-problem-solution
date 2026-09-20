class Solution {
public:
    int solve(int i, int currentSum, vector<int>& nums, int target, vector<vector<int>> &dp, int offset){
        if(i == nums.size()) return currentSum == target ? 1 : 0;

        int j = currentSum + offset;

        if(dp[i][j] != -1) return dp[i][j];

        int plus = solve(i+1, currentSum + nums[i], nums, target, dp, offset);
        int minus = solve(i+1, currentSum - nums[i], nums, target, dp, offset);

        return dp[i][j] = plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n, vector<int>(total * 2 + 1, -1));


        return solve(0, 0, nums, target, dp, total);
    }
};
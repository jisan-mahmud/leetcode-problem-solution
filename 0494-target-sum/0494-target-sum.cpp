class Solution {
public:
    int solve(int i, int currentSum, vector<int>& nums, int target, vector<vector<int>> &dp){
        if(i == nums.size()) return currentSum == target ? 1 : 0;

        int plus = solve(i+1, currentSum + nums[i], nums, target, dp);
        int minus = solve(i+1, currentSum - nums[i], nums, target, dp);

        return plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(1001, -1));

        return solve(0, 0, nums, target, dp);
    }
};
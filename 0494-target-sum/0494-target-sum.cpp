class Solution {
public:

    int solve(int i, int currentSum, vector<int>& nums, int target,
 vector<unordered_map<int, int>>& dp) {

        if (i == nums.size()) {
            return currentSum == target ? 1 : 0;
        }


        if (dp[i].count(currentSum)) {
            return dp[i][currentSum];
        }

        int plus = solve(i + 1, currentSum + nums[i], nums, target, dp);


        int minus = solve(i + 1, currentSum - nums[i], nums, target, dp);

        return dp[i][currentSum] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        vector<unordered_map<int, int>> dp(n);

        return solve(0, 0, nums, target, dp);
    }
};
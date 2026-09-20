class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> dp;  
        dp[0] = 1;                 

        for (int x : nums) {
            unordered_map<int, int> next;

            for (auto& [sum, ways] : dp) {
                next[sum + x] += ways;   
                next[sum - x] += ways; 
            }

            dp = next;
        }

        return dp[target];
    }
};
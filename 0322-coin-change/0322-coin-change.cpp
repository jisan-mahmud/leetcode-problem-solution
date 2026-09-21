class Solution {
public:
    int solve(int amount, vector<int> &coins, vector<int> &dp){
        if(amount == 0) return 0;

        if(dp[amount] != -1) return dp[amount];

        int ans = INT_MAX - 1;

        for(int i = 0; i < coins.size(); i++){
            if(coins[i] <= amount){
                int pick = solve(amount - coins[i], coins, dp) + 1;
                ans = min(pick, ans);
            }
        }


        
        return dp[amount] = ans;

    }


    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, -1);

        int ans = solve(amount, coins, dp);

        return ans == INT_MAX - 1 ? -1 : ans;
    }
};
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n+1, vector<int>(amount+1, INT_MAX - 1));

        for(int i = 0; i <= n; i++){
            dp[i][0] = 0;
        }

        for(int i = n - 1; i >= 0; i--){
            for(int j = 1; j <= amount; j++){
                int take = INT_MAX - 1;
                if(coins[i] <= j) take = dp[i][j - coins[i]] + 1;

                int not_take = dp[i+1][j];

                dp[i][j] = min(take, not_take);
            }
        }

        int ans = dp[0][amount];

        return ans != INT_MAX - 1 ? ans : -1;
    }
};
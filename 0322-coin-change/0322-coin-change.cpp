class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, INT_MAX - 1);

        dp[0] = 0;

        for(int a = 1; a <= amount; a++){
            int ans = INT_MAX - 1;

            for(int i = 0; i < n; i++){
                if(coins[i] <= a){
                    ans = min(ans, dp[a - coins[i]] + 1);
                }
            }

            dp[a] = ans;
        }


        int ans = dp[amount];

        return ans == INT_MAX - 1 ? -1 : ans;
    }
};
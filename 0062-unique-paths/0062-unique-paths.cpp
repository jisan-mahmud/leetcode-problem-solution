class Solution {
public:

    int solve(int m, int n, vector<vector<int>> &dp){
        if(m == 0 and n == 0) return 1;

        if(m < 0 or n < 0) return 0;

        if(dp[m][n] != -1) return dp[m][n];

        int ans = solve(m, n - 1, dp) + solve(m - 1, n, dp);

        return dp[m][n] = ans;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[0][0] = 1;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 and j == 0) continue;

                int left = 0, down = 0;

                if(i > 0) down = dp[i-1][j];
                if(j > 0) left = dp[i][j-1];
                dp[i][j] = left + down;
            }
        }

        return dp[m-1][n-1];
    }
};
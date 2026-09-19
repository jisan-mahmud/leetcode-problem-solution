class Solution {
public:
    int solve(vector<vector<int>> &triangle, int i, int j, vector<vector<int>> &dp){
       if(i == triangle.size() - 1) return triangle[i][j];

       if(dp[i][j] != INT_MIN) return dp[i][j];

       int down = solve(triangle, i+1, j, dp);
       int dia = solve(triangle, i+1, j + 1, dp);

       return dp[i][j] = min(down, dia) + triangle[i][j];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        dp[0][0] = triangle[0][0];

        for(int i = 1; i < n; i++){
            for(int j = 0; j <= i; j++){
                int up = j < i ? dp[i-1][j] : INT_MAX;
                int dia = j > 0 ? dp[i-1][j-1] : INT_MAX;
                dp[i][j] = min(up, dia) + triangle[i][j];
            }
        }

        int ans = *min_element(dp[n-1].begin(), dp[n-1].end());

        return ans;
    }
};
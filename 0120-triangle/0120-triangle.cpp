class Solution {
public:
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
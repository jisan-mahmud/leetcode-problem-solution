class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int x =  cost[0];
        int y = cost[1];

        for(int i = 2; i < n; i++) {
            int ans = cost[i] + min(y, x);
            x = y;
            y = ans;
        }

        return min(x, y);
    }
};
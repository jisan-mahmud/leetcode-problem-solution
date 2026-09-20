class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int total = 0;
        for (int x : nums)
            total += x;

        if (abs(target) > total)
            return 0;

        int offset = total;

        vector<int> dp(2 * total + 1, 0);
        dp[offset] = 1;  // sum = 0

        for (int x : nums) {

            vector<int> next(2 * total + 1, 0);

            for (int sum = -total; sum <= total; sum++) {

                if (dp[sum + offset] == 0)
                    continue;

                int ways = dp[sum + offset];

                next[sum + x + offset] += ways;
                next[sum - x + offset] += ways;
            }

            dp = next;
        }

        return dp[target + offset];
    }
};
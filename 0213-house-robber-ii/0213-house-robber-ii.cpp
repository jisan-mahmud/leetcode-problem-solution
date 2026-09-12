class Solution {
public:
    int solve(vector<int>& nums, int st, int end){
        if(st == end) return nums[st];

        int x = nums[st];
        int y = max(nums[st], nums[st + 1]);

        for(int i = st + 2; i <= end; i++){
            int ans = max(y, x + nums[i]);
            x = y;
            y = ans;
        }

        return y;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        return max(solve(nums, 0, n - 2), solve(nums, 1, n - 1));
    }
};
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int sum = 0;
        long long ans = 0;
        cnt[0] = 1;

        for(auto val:nums){
            sum+=val;
            ans+=cnt[sum-k];
            cnt[sum]++;
        }

        return ans;
        
    }
};

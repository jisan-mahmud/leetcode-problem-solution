class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {

        int l = 0, r = -1;

        vector<int> cnt(30, 0);

        int mx = 0;

        while(r+1 < nums.size()){
            r++;

            int x = nums[r];

            bool is_valid = true;

            for(int i = 0;i < 30;i++){
                if(x & (1 << i)) cnt[i]++;
                if(cnt[i] > 1) is_valid = false;
            }

            if(!is_valid){
                while(l < r){
                    int y = nums[l];
                    l++;

                    bool is_valid = true;

                    for(int i = 0;i < 30;i++){
                        if(y & (1 << i)) cnt[i]--;
                        if(cnt[i] > 1) is_valid = false;
                    }

                    if(is_valid) break;
                }
            }

            mx = max(r-l+1, mx);
        }

        return mx;
        
    }
};

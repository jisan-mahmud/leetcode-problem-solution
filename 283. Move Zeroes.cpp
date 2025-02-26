class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;

        for(int r = 0;r < nums.size();r++){
            swap(nums[l], nums[r]);
            if(nums[l]) l++;
        }
    }
};

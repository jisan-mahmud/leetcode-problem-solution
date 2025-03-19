class Solution {
public:
    void fill(vector<int> &nums, int pos){
        nums[pos] ^= 1;
        nums[pos+1] ^= 1;
        nums[pos+2] ^= 1;
    }
    int minOperations(vector<int>& nums) {
        int operations = 0;

        for(int i = 0;i < nums.size() - 2;i++){
            if(nums[i] != 1){
                fill(nums, i);
                operations++;
            }
        }

        if(nums[nums.size() - 1] == 0 || nums[nums.size()-2] == 0) return -1;
        else return operations;

    }
};

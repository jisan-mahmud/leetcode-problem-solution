class Solution {
private:
    int find(vector<int>& nums, int target, int low, int high){
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int n = nums.size();

        while(low < high){
            int mid = low + (high - low) / 2;
            if(nums[mid] > nums[high])
                low = mid + 1;
            else
                high = mid; 
        }

       
        if(target >= nums[low] && target <= nums[n - 1]){ 
            return find(nums, target, low, n - 1);
        }
        return find(nums, target, 0, low - 1);
    }
};
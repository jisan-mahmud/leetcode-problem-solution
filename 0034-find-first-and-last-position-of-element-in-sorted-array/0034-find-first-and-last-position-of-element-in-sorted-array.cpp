class Solution {
private:
    int findUpperBound(vector<int>& nums, int target){
        int low = 0, high = nums.size() - 1;
        int i = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target){
                i = mid;
                low = mid + 1;
            }else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }

        return i;
    }

    int findLowerBound(vector<int>& nums, int target){
        int low = 0, high = nums.size() - 1;
        int j = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target){
                j = mid;
                high = mid - 1;
            }else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }

        return j;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int startPosition = findLowerBound(nums, target);
        int endPosition = findUpperBound(nums, target);

        return {startPosition, endPosition};
    }
};
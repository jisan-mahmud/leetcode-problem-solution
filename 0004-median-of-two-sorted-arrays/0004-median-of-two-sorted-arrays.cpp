class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int total = nums1.size() + nums2.size();

        int low = 0;
        int high = nums1.size();

        while(low <= high){

            int partitionX = (low + high) / 2;
            int partitionY = (total + 1) / 2 - partitionX;

            int l1 = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int r1 = (partitionX == nums1.size()) ? INT_MAX : nums1[partitionX];

            int l2 = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int r2 = (partitionY == nums2.size()) ? INT_MAX : nums2[partitionY];

            if(l1 <= r2 && l2 <= r1){
                if(total % 2 == 1){
                    return max(l1, l2);
                }
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }

            if(l1 > r2){
                high = partitionX - 1;
            }

            else{
                low = partitionX + 1;
            }
        }

        return 0.0;
    }
};
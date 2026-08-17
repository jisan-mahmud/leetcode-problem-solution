class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int kthSmallest;
        int low = 0, high = n * m;

        while(low <= high){
            int mid = low + (high - low) / 2;
            int smallestCount = 0;

            for(int row = 1; row <= m; row++){
                smallestCount += min(n, mid / row);
            }

            // if(smallestCount == k) {
                
            //     break;
            // }

            if(smallestCount >= k){
                high = mid - 1;
                kthSmallest = mid;
            }else{
                low = mid + 1;
            }
        }

        return kthSmallest;
    }
};
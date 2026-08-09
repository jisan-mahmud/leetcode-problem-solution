class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > arr[mid + 1]) {
                high = mid;       // peak is at mid or to the left
            } else {
                low = mid + 1;    // peak is to the right
            }
        }
        return low;
    }
};
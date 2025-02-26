class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        vector<int> new_arr;
        int l = 0, r = 0;
        while(m > 0 && n > 0){
            if(nums1[l] < nums2[r]){
                new_arr.push_back(nums1[l]);
                l++;
                m--;
            }else{
                new_arr.push_back(nums2[r]);
                r++;
                n--;
            }
        }

        while(m > 0){
            new_arr.push_back(nums1[l]);
            l++;
            m--;
        }
        while(n > 0){
            new_arr.push_back(nums2[r]);
            r++;
            n--;
        }

        nums1 = new_arr;

    }
};

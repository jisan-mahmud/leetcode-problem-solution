#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set= tree <T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {

        vector<int> arr1;
        vector<int> arr2;


        ordered_set<int> ord_arr1;
        ordered_set<int> ord_arr2;

        ord_arr1.insert(nums[0]);
        ord_arr2.insert(nums[1]);

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for(int i = 2;i < nums.size();i++){
            if(ord_arr1.order_of_key(nums[i]) > ord_arr2.order_of_key(nums[i])){
                ord_arr1.insert(nums[i]);
                arr1.push_back(nums[i]);
            }else if(ord_arr1.order_of_key(nums[i]) < ord_arr2.order_of_key(nums[i])){
                ord_arr2.insert(nums[i]);
                arr2.push_back(nums[i]);
            }else{
                if(ord_arr2.size() < ord_arr1.size()){
                    ord_arr2.insert(nums[i]);
                    arr2.push_back(nums[i]);
                }else{
                    ord_arr1.insert(nums[i]);
                    arr1.push_back(nums[i]);
                }
            }
        }

        arr1.insert(arr1.end(), arr2.begin(), arr2.end()); 

        return arr1;
    }
};

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using ordered_set= tree <T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        ordered_set<int> pst;
        vector<int> cnts;
        for(int i = nums.size() - 1;i >= 0; i--){
            pst.insert(nums[i]);
            cnts.push_back(pst.order_of_key(nums[i]));
        }

        reverse(cnts.begin(), cnts.end());
        return cnts;
    }
};

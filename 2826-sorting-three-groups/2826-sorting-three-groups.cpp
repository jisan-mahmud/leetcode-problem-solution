class Solution {
public:
    int minimumOperations(vector<int>& nums) {

        vector<int> lis;

        for(int x : nums){

            auto it = upper_bound(lis.begin(), lis.end(), x);

            if(it == lis.end()){
                lis.push_back(x);
            }
            else{
                *it = x;
            }
        }

        return nums.size() - lis.size();
        
    }


};
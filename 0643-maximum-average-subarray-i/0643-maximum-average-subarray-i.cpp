class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        double ans = INT_MIN;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];

            if(i - k + 1 >= 0){
                if(i - k + 1 == 0) ans = max(ans, sum / k);
                else{
                    sum -= nums[i - k];
                    ans = max(ans, sum / k); 
                }
            }
        }

        return ans;
    }
};
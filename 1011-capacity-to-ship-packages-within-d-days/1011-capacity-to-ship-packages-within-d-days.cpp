class Solution {
private:
    bool isPossible(vector<int>& weights, int maxWeight, int days){
        int takeWeights = 0, takeDays = 0;

        for(int w: weights){
            if(takeWeights + w <= maxWeight){
                takeWeights += w;
            }else{
                takeWeights = w;
                takeDays++;
            }

            if(takeDays >= days) return false;
        }

        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = weights[0], high = 0;

        for(int w : weights){
            low = max(low, w);
            high += w;
        }

        while(low < high){
            int mid = low + (high - low) / 2;
            if(isPossible(weights, mid, days))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};
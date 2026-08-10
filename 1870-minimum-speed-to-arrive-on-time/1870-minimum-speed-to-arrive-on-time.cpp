class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 0, high = 10000001;

        while(low < high){
            int mid = low + (high - low) / 2;
            double total_times = 0;

            for(int i = 0; i < dist.size(); i++){
                if(i == dist.size() - 1){
                    total_times += (double)dist[i] / (double)mid;
                }else{
                    total_times += ceil((double)dist[i] / (double)mid);
                }
            }

            if(total_times > hour) low = mid + 1;
            else high = mid; 

        }

        return low == 10000001 ? -1 : low;
    }
};
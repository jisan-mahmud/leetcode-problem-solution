class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> mis;

        for(int i = 1; i < arr[0]; i++){
            mis.push_back(i);
        }

        for(int i = 0; i < arr.size() - 1; i++){
            for(int j = arr[i] + 1; j < arr[i+1]; j++){
                mis.push_back(j);
            }
        }

        int i = arr.back();

        while(mis.size() < k){
            mis.push_back(++i);
        }

        return mis[k-1];
    }
};
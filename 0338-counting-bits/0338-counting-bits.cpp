class Solution {
public:
    int bitCount(int x){
        int cnt = 0;
        while(x){
            if(x % 2) cnt++;
            x/=2;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> ans;

        for(int i = 0; i <= n; i++){
            ans.push_back(bitCount(i));
        }

        return ans;
    }
};
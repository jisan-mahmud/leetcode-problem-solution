class Solution {
private:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0]){
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        vector<int> maxEnvelope(n+1, INT_MAX);
        maxEnvelope[0] = 0;

        sort(envelopes.begin(), envelopes.end(), cmp);

        int maxLength = 1;

        for(auto& envelope: envelopes){
            int index = lower_bound(maxEnvelope.begin(), maxEnvelope.end(), envelope[1]) - maxEnvelope.begin();
            maxLength = max(maxLength, index);
            maxEnvelope[index] = envelope[1];
        }

        return maxLength;
    }
};
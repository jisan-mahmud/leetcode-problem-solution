class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> lastSeen(256, -1);

        int ans = 0;
        int start = 0;

        for(int i = 0; i < s.size(); i++){
            char c = s[i];

            if(lastSeen[c] >= start){
                start = lastSeen[c] + 1;
            }

            lastSeen[c] = i;

            ans = max(ans, i - start + 1);
        }

        return ans;
        
    }
};
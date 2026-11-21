
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        int maxLen = 0;

        for (string word : wordDict) {
            maxLen = max(maxLen, (int)word.size());
        }

        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.size(); i++) {
            for (int j = i - 1; j >= max(0, i - maxLen); j--) {
                if (dp[j] && dict.contains(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};

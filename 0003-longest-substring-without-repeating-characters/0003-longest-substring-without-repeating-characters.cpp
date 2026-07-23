class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        deque<char> wnd;
        vector<int> cnt(256, 0);   // <-- big enough for any char
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            wnd.push_back(s[i]);
            cnt[(unsigned char)s[i]]++;   // <-- index by the char itself

            while (cnt[(unsigned char)s[i]] > 1) {
                char x = wnd.front();
                wnd.pop_front();
                cnt[(unsigned char)x]--;
            }

            ans = max(ans, (int)wnd.size());
        }

        return ans;
    }
};
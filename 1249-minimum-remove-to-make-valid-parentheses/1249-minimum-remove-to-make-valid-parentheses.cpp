class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        int open = 0;

        for(char c : s) {
            if(c == '(') {
                open++;
            }
            else if(c == ')') {
                if(open == 0) continue;
                open--;
            }

            ans += c;
        }

        string res = "";
        int remove = open;

        for(int i = ans.size() - 1; i >= 0; i--) {
            if(ans[i] == '(' && remove > 0) {
                remove--;
                continue;
            }

            res += ans[i];
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
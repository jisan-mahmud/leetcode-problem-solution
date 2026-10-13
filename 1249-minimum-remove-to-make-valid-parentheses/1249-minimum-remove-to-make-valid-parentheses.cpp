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

        for(int i = ans.size() - 1; i >= 0; i--) {
            if(ans[i] == '(' && open > 0) {
                open--;
                continue;
            }

            res += ans[i];
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
class Solution {
    string longPalindrom(string &s, int l, int r){
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            l--;
            r++;
        }

        return s.substr(l+1, r - l - 1);
    }
public:
    string longestPalindrome(string s) {
        if(s.empty()) return s;

        string longestStr = "";

        for(int i = 0;i < s.size();i++){

            string oddStr = longPalindrom(s, i, i);
            string evenStr = longPalindrom(s, i, i+1);

            if(oddStr.size() > longestStr.size()) longestStr = oddStr;
            if(evenStr.size() > longestStr.size()) longestStr = evenStr;

        }

        return longestStr;
        
    }
};

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int k = p.size();

        if(k > n) return {};

        vector<int> p_cout(26, 0);

        for(char c:p){
            p_cout[c - 'a']++;
        }

        deque<char> window;
        vector<int> window_cout(26, 0);

        for(int i = 0;i < k;i++){
            window.push_back(s[i]);
            window_cout[s[i] - 'a']++;
        }

        vector<int> ans;

        for(int i = 0;i <= n - k;i++){

            bool matched = true;

            for(int i = 0;i < 26;i++){
                if(window_cout[i] != p_cout[i]) matched = false;
            }

            if(matched) ans.push_back(i);

            char x = window.front();
            window.pop_front();
            window_cout[x - 'a']--;

            if(i >= n - k) break;

            window.push_back(s[i+k]);
            window_cout[s[i+k] - 'a']++;


        }

        return ans;
    
    }
};

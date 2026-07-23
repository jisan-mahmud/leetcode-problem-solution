class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> p_cnt(26, 0), wnd_cnt(26, 0), ans;

        int n = s.size();
        int k = p.size();

        if(k > n) return {};

        for(char c : p){
            p_cnt[c - 'a']++;
        }

        for(int i = 0; i < k; i++){
            wnd_cnt[s[i] - 'a']++;
        }

        for(int i = 0; i <= n - k; i++){
            bool matched = true;

            for(int j = 0; j < 26; j++){
                if(p_cnt[j] != wnd_cnt[j]){
                    matched = false;
                }
            }

            if(matched) ans.push_back(i);
            if(i >= n - k) break;
            wnd_cnt[s[i] - 'a']--;
            wnd_cnt[s[i+k] - 'a']++;
        }

        return ans;
    }
};
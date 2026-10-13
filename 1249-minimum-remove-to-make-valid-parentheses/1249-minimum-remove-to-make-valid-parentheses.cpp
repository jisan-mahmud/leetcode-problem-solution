class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<int, char>> st;

        string temps = "";

        string newS = "";

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') {
                st.push({temps.size(), s[i]});
                temps += s[i];
            }
            else if(s[i] == ')'){
                if(!st.empty()){
                    auto [idx, c] = st.top();
                    if(c == '(') {
                        st.pop();
                        temps+=s[i];
                    }
                }
            }else temps+=s[i];
        }
        
        cout << temps.size() << st.size();

        for(int i = temps.size()-1; i >= 0; i--){
            if(!st.empty()){
                auto [idx, c] = st.top();
                if(idx == i) {
                    st.pop();
                    continue;
                }
                newS+=temps[i];
                continue;
            }
            newS+=temps[i];
        }

        reverse(newS.begin(), newS.end());

        return newS;

    }

};
class Solution {
public:
    vector<int> parent;

    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y){
        x = find(x);
        y = find(y);

        if(x != y){
            parent[x] = y;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);

        for(int i = 0; i < 26; i++){
            parent[i] = i;
        }

        for(auto equation: equations){
            char c1 = equation[0];
            char c2 = equation[3];

            if(equation[1] == '='){
                unite(c1 - 'a', c2 - 'a');
            }
        }

        for(auto equation: equations){
            char c1 = equation[0];
            char c2 = equation[3];

            if(equation[1] == '!'){
                if(find(c1 - 'a') == find(c2 - 'a')) return false;
            }
        }

        return true;

    }
};
class Solution {
public:
    vector<int> parent;

    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    bool unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x != y){
            parent[x] = y;
            return true;
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);

        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            if(!unite(u, v)){
                return {u, v};
            }
        }

        return {0, 0};
    }
};
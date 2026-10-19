class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    bool unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return false;
        if(rank[x] < rank[y]){
            parent[x] = y;
        }else if(rank[x] > rank[y]){
            parent[y] = x;
        }else{
            parent[x] = y;
            rank[y]++;
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        rank.assign(n+1, 0);

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
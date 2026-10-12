class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);

        for(int i = 0; i < flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int p = flights[i][2];

            graph[u].push_back({v, p});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        queue<tuple<int, int, int>> q;
        q.push({src, 0, 0});

        while(!q.empty()){
            auto [u, w, stops] = q.front();
            q.pop();

            if(stops > k) continue;

            for(auto child : graph[u]){
                auto [v, price] = child;

                if(dist[v] > w + price && stops <= k){
                    dist[v] = w + price;
                    q.push({v, dist[v], stops + 1});
                }
            }
        }

        if(dist[dst] != INT_MAX) return dist[dst];
        return -1;
    }
};
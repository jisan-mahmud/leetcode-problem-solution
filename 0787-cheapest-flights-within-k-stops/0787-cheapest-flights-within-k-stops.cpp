class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<int> temp = dist;

            for (auto& f : flights) {
                int u = f[0];
                int v = f[1];
                int p = f[2];

                if (dist[u] != INT_MAX && dist[u] + p < temp[v]) {
                    temp[v] = dist[u] + p;
                }
            }

            if (temp == dist) break;       
            dist = temp;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
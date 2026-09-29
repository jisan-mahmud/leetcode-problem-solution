class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n);

        for(auto road : roads){
            int u = road[0];
            int v = road[1];
            int t = road[2];

            graph[u].push_back({v, t});
            graph[v].push_back({u, t});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        pq.push({0, 0});

        while(!pq.empty()){
            auto [nodeTime, node] = pq.top();
            pq.pop();

            for(auto child : graph[node]){
                auto [childNode, childTime] = child;

                long long needTime = nodeTime + childTime;

                if(dist[childNode] > needTime){
                    dist[childNode] = needTime;
                    ways[childNode] = ways[node];

                    pq.push({needTime, childNode});
                }
                else if(dist[childNode] == needTime){
                    ways[childNode] = (ways[childNode] + ways[node]) % 1000000007;
                }
            }
        }

        return ways[n-1];
    }
};
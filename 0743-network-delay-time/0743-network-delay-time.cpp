class Solution {
public:
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);

        for(auto time : times){
            int u = time[0];
            int v = time[1];
            int w = time[2];
            graph[u].push_back({v, w});
        }

        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        min_heap.push({0, k});

        while(!min_heap.empty()){
            auto source = min_heap.top();
            min_heap.pop();

            for(auto target: graph[source.second]){
                int target_node = target.first;
                int target_weight = target.second;

                if(dist[target_node] <= target_weight + source.first) continue;

                int w = target_weight + source.first;
                dist[target_node] = w;

                min_heap.push({w, target_node});
            }
        }

        int ans = 0;

        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX){
                return -1;
            }

            ans = max(ans, dist[i]);
        }

        return ans;

    }
};
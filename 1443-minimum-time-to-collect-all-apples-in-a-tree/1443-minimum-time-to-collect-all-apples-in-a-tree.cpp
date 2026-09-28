class Solution {
public:

    int dfs(int current, int parent, vector<vector<int>>& graph, vector<bool>& hasApple) {

        int time = 0;

        for (auto child : graph[current]) {

            if (child == parent)
                continue;

            int childTime = dfs(child, current, graph, hasApple);

            if (childTime > 0 || hasApple[child]) {
                time += childTime + 2;
            }
        }

        return time;
    }


    int minTime(int n, vector<vector<int>>& edges,
                vector<bool>& hasApple) {

        vector<vector<int>> graph(n);

        for (auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        return dfs(0, -1, graph, hasApple);
    }
};
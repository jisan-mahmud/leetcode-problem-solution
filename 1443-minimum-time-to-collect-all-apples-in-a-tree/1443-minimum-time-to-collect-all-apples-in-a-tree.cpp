class Solution {
public:

    void dfs(int current,
             int parent,
             vector<vector<int>>& graph,
             vector<bool>& hasApple,
             int& answer) {

        for (auto child : graph[current]) {

            if (child == parent)
                continue;

            dfs(child, current, graph, hasApple, answer);

            // If this child's subtree contains an apple,
            // we must travel current -> child -> current.
            if (hasApple[child]) {
                answer += 2;

                // Mark current as containing an apple
                // because its child's subtree has one.
                hasApple[current] = true;
            }
        }
    }

    int minTime(int n,
                vector<vector<int>>& edges,
                vector<bool>& hasApple) {

        vector<vector<int>> graph(n);

        // Tree is undirected
        for (auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int answer = 0;

        dfs(0, -1, graph, hasApple, answer);

        return answer;
    }
};
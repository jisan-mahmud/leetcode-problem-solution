
class Solution {
public:
    bool dfs(int src, vector<vector<int>>& graph, vector<int>& visited) {
        visited[src] = 1;

        for (int child : graph[src]) {
            if (visited[child] == 1) return false;

            if (visited[child] == -1) {
                if (!dfs(child, graph, visited)) return false;
            }

            if (visited[child] == 2) continue;
        }

        visited[src] = 2;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> visited(n, -1);

        for (int i = 0; i < n; i++) {
            if (visited[i] != -1) continue;

            dfs(i, graph, visited);
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (visited[i] == 2) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

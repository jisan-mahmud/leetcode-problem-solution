
class Solution {
public:
    bool dfs(int src, vector<vector<int>>& graph, vector<int>& visited, stack<int>& st) {

        visited[src] = 1; 

        for (int child : graph[src]) {
            if (visited[child] == 1) return false; 

            if (visited[child] == -1) {
                if (!dfs(child, graph, visited, st))
                    return false;
            }
        }

        visited[src] = 2;
        st.push(src);

        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);

        for (const auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }

        vector<int> visited(numCourses, -1);
        stack<int> st;

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == -1) {
                if (!dfs(i, graph, visited, st)) return {};
            }
        }

        vector<int> result;
        // result.reserve(numCourses);

        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};

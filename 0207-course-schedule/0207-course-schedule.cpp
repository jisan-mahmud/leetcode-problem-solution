class Solution {
public:
    bool dfs(int src, vector<vector<int>> &graph, vector<int> &visited){
        visited[src] = 1;

        for(int child : graph[src]){
            if(visited[child] == 1) return false;
            if(visited[child] == -1){
                if(!dfs(child, graph, visited)) return false;
            }
        }
        visited[src] = 2;

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> graph(n);

        for(int i = 0; i < prerequisites.size(); i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> visited(n, -1);

        for(int i = 0; i < n; i++){
            if(visited[i] != -1) continue;

            if(!dfs(i, graph, visited)) return false;
        }

        return true;
    }
};
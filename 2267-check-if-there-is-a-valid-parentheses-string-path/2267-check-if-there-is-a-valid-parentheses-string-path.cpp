class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int maxBal = n + m;

        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(maxBal + 1, false)));

        queue<tuple<int,int,int>> q;
        int startBal = (grid[0][0] == '(') ? 1 : -1;
        if (startBal < 0) return false; 

        visited[0][0][startBal] = true;
        q.push({0, 0, startBal});

        int dirs[2][2] = {{0,1}, {1,0}};

        while (!q.empty()) {
            auto [i, j, bal] = q.front(); q.pop();

            if (i == n-1 && j == m-1 && bal == 0) return true;

            for (auto& d : dirs) {
                int ni = i + d[0], nj = j + d[1];
                if (ni >= n || nj >= m) continue;

                int nb = bal + (grid[ni][nj] == '(' ? 1 : -1);
                if (nb < 0 || nb > maxBal) continue;
                if (visited[ni][nj][nb]) continue;

                visited[ni][nj][nb] = true;
                q.push({ni, nj, nb});
            }
        }

        return false;
    }
};
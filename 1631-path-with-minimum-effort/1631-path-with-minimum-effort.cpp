class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});

        while (!pq.empty()) {

            auto current = pq.top();
            pq.pop();

            int effort = current[0];
            int row = current[1];
            int col = current[2];

            for (int direction = 0; direction < 4; direction++) {

                int newRow = row + dr[direction];
                int newCol = col + dc[direction];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {

                    int edgeEffort = abs(heights[row][col] - heights[newRow][newCol]);

                    int newEffort = max(effort, edgeEffort);

                    if (newEffort < dist[newRow][newCol]) {

                        dist[newRow][newCol] = newEffort;

                        pq.push({newEffort, newRow, newCol});
                    }
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};
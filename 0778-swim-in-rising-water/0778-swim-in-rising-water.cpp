class Solution {
private:
    int n;
    bool canReach(vector<vector<int>>& grid, int t){
        if(grid[0][0] > t) return false;

        queue<pair<int, int>> q;
        vector< vector<bool>> visited(n, vector<bool>(n, false));
        q.push({0, 0});
        visited[0][0] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};


        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            if(n - 1 == r && n - 1 == c) return true;

            for(int i = 0; i < 4; i++){
                int nr = dr[i] + r;
                int nc = dc[i] + c;

                if(nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc] && grid[nr][nc] <= t){
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }

        return false;
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();

        int low = 0, high = n * n - 1;
        while(low < high){
            int mid = low + (high - low) / 2;

            if(canReach(grid, mid)){
                high = mid;
            }else{
                low = mid + 1;
            }
        }

        return low;
    }
};
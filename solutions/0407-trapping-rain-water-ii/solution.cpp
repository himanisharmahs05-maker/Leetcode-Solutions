class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();

        if (m <= 2 || n <= 2)
            return 0;

        priority_queue<pair<int, pair<int,int>>,
                       vector<pair<int, pair<int,int>>>,
                       greater<pair<int, pair<int,int>>>> pq;

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][n-1], {i, n-1}});
            vis[i][0] = vis[i][n-1] = true;
        }

        for (int j = 1; j < n - 1; j++) {
            pq.push({heightMap[0][j], {0, j}});
            pq.push({heightMap[m-1][j], {m-1, j}});
            vis[0][j] = vis[m-1][j] = true;
        }

        int ans = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [h, pos] = pq.top();
            pq.pop();

            int r = pos.first, c = pos.second;

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n || vis[nr][nc])
                    continue;

                vis[nr][nc] = true;
                ans += max(0, h - heightMap[nr][nc]);

                pq.push({max(h, heightMap[nr][nc]), {nr, nc}});
            }
        }

        return ans;
    }
};


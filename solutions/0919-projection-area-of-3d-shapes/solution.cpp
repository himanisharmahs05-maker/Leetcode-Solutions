class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int area = 0;

        for (int i = 0; i < n; i++) {

            int rowMax = 0;
            int colMax = 0;

            for (int j = 0; j < n; j++) {

                // Top view
                if (grid[i][j] > 0)
                    area++;

                // Front view
                rowMax = max(rowMax, grid[i][j]);

                // Side view
                colMax = max(colMax, grid[j][i]);
            }

            area += rowMax;
            area += colMax;
        }

        return area;
    }
};

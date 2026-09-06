class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0);
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }

            stack<int> st;

            for (int j = 0; j <= n; j++) {
                int h = (j == n ? 0 : heights[j]);

                while (!st.empty() && heights[st.top()] > h) {
                    int height = heights[st.top()];
                    st.pop();

                    int width = st.empty() ? j : j - st.top() - 1;
                    ans = max(ans, height * width);
                }

                st.push(j);
            }
        }

        return ans;
    }
};

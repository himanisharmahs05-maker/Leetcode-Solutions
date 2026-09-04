class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = INT_MIN;

        for (int left = 0; left < n; left++) {
            vector<int> rowSum(m, 0);

            for (int right = left; right < n; right++) {
                for (int i = 0; i < m; i++)
                    rowSum[i] += matrix[i][right];

                set<int> st;
                st.insert(0);
                int sum = 0;

                for (int x : rowSum) {
                    sum += x;
                    auto it = st.lower_bound(sum - k);

                    if (it != st.end())
                        ans = max(ans, sum - *it);

                    st.insert(sum);
                }
            }
        }

        return ans;
    }
};

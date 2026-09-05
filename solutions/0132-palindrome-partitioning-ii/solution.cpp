class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 1 || pal[i + 1][j - 1]))
                    pal[i][j] = true;
            }
        }

        dp[0] = -1;

        for (int i = 1; i <= n; i++) {
            dp[i] = i - 1;
            for (int j = 0; j < i; j++) {
                if (pal[j][i - 1])
                    dp[i] = min(dp[i], dp[j] + 1);
            }
        }

        return dp[n];
    }
};

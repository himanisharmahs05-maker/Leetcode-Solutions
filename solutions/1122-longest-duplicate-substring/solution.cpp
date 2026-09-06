class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.size();
        string ans = "";

        auto check = [&](int len) -> int {
            unordered_map<long long, vector<int>> mp;
            long long base = 256;
            long long mod = 1000000007;
            long long hash = 0, power = 1;

            for (int i = 0; i < len; i++) {
                hash = (hash * base + s[i]) % mod;
                power = power * base % mod;
            }

            mp[hash].push_back(0);

            for (int i = len; i < n; i++) {
                hash = (hash * base - s[i - len] * power % mod + mod) % mod;
                hash = (hash + s[i]) % mod;

                int start = i - len + 1;

                for (int prev : mp[hash]) {
                    if (s.substr(prev, len) == s.substr(start, len))
                        return start;
                }

                mp[hash].push_back(start);
            }

            return -1;
        };

        int low = 1, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int start = check(mid);

            if (start != -1) {
                ans = s.substr(start, mid);
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

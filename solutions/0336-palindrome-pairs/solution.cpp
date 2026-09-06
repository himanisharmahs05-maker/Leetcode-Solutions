class Solution {
public:
    bool isPal(string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> mp;
        vector<vector<int>> ans;

        for (int i = 0; i < words.size(); i++) {
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            mp[rev] = i;
        }

        for (int i = 0; i < words.size(); i++) {
            string &w = words[i];
            int n = w.size();

            for (int j = 0; j <= n; j++) {
                if (isPal(w, j, n - 1)) {
                    string left = w.substr(0, j);
                    if (mp.count(left) && mp[left] != i)
                        ans.push_back({i, mp[left]});
                }

                if (j > 0 && isPal(w, 0, j - 1)) {
                    string right = w.substr(j);
                    if (mp.count(right) && mp[right] != i)
                        ans.push_back({mp[right], i});
                }
            }
        }

        return ans;
    }
};

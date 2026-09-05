class Solution {
public:
    unordered_map<string, bool> mp;

    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;

        string key = s1 + "#" + s2;
        if (mp.count(key)) return mp[key];

        int n = s1.size();

        int cnt[26] = {};
        for (int i = 0; i < n; i++) {
            cnt[s1[i] - 'a']++;
            cnt[s2[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++)
            if (cnt[i] != 0)
                return mp[key] = false;

        for (int k = 1; k < n; k++) {
            if (isScramble(s1.substr(0, k), s2.substr(0, k)) &&
                isScramble(s1.substr(k), s2.substr(k)))
                return mp[key] = true;

            if (isScramble(s1.substr(0, k), s2.substr(n - k)) &&
                isScramble(s1.substr(k), s2.substr(0, n - k)))
                return mp[key] = true;
        }

        return mp[key] = false;
    }
};

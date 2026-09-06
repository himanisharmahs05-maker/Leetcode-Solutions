class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo;

        function<vector<string>(int)> dfs = [&](int start) {
            if (start == s.size())
                return vector<string>{""};

            if (memo.count(start))
                return memo[start];

            vector<string> res;

            for (int end = start + 1; end <= s.size(); end++) {
                string word = s.substr(start, end - start);

                if (!st.count(word))
                    continue;

                for (string tail : dfs(end)) {
                    if (tail.empty())
                        res.push_back(word);
                    else
                        res.push_back(word + " " + tail);
                }
            }

            return memo[start] = res;
        };

        return dfs(0);
    }
};

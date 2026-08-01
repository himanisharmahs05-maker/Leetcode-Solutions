class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";

        unordered_map<char, int> mp;

        for (char c : row1)
            mp[c] = 1;

        for (char c : row2)
            mp[c] = 2;

        for (char c : row3)
            mp[c] = 3;

        vector<string> ans;

        for (string word : words) {
            int row = mp[tolower(word[0])];
            bool valid = true;

            for (char c : word) {
                if (mp[tolower(c)] != row) {
                    valid = false;
                    break;
                }
            }

            if (valid)
                ans.push_back(word);
        }

        return ans;
    }
};

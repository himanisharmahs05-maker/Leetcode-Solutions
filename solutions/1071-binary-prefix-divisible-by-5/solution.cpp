class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> res;
        int num = 0;

        for (int bit : nums) {
            num = (num * 2 + bit) % 5;

            if (num == 0)
                res.push_back(true);
            else
                res.push_back(false);
        }
        return res;
    }
};

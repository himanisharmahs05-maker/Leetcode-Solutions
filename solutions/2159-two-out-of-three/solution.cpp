class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, int> mp;

        for (int x : nums1) mp[x] |= 1;
        for (int x : nums2) mp[x] |= 2;
        for (int x : nums3) mp[x] |= 4;

        vector<int> res;

        for (auto &it : mp) {
            int mask = it.second;

            // check if at least 2 bits are set
            if ((mask & (mask - 1)) != 0)
                res.push_back(it.first);
        }

        return res;
    }
};

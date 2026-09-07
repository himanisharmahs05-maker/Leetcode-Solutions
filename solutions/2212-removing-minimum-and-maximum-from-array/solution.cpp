class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minpos = 0, maxpos = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minpos])
                minpos = i;

            if (nums[i] > nums[maxpos])
                maxpos = i;
        }

        int left = min(minpos, maxpos);
        int right = max(minpos, maxpos);

        int removeLeft = right + 1;
        int removeRight = n - left;
        int removeBoth = (left + 1) + (n - right);

        return min({removeLeft, removeRight, removeBoth});
    }
};

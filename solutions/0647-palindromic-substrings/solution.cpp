class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {

            int left = i, right = i;  //odd

            while (left >= 0 && right < n &&
                   s[left] == s[right]) {
                ans++;
                left--;            //expand for odd
                right++;
            }

            left = i;             //even
            right = i + 1;

            while (left >= 0 && right < n &&
                   s[left] == s[right]) {
                ans++;
                left--;         //expand for even
                right++;
            }
        }

        return ans;
    }
};

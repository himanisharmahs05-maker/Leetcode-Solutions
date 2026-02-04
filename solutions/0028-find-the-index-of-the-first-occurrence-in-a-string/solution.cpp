class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        // loop till possible starting positions
        for(int i = 0; i <= n - m; i++){
            int j = 0;

            // check character by character
            while(j < m && haystack[i + j] == needle[j]){
                j++;
            }

            // if full needle matched
            if(j == m)
                return i;
        }
        return -1;
    }
};


class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        
        string hex = "0123456789abcdef";
        string res = "";
        
        unsigned int n = num;  // handles negative
        
        while (n != 0) {
            res = hex[n & 15] + res;
            n >>= 4;
        }
        
        return res;
    }
};

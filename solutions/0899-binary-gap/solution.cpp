class Solution {
public:
    int binaryGap(int n) {
        int last = -1;   // last 1 ka index
        int pos = 0;     // current position
        int maxGap = 0;

        while (n > 0) {
            if (n & 1) {  // agar bit 1 hai
                if (last != -1) {
                    maxGap = max(maxGap, pos - last);
                }
                last = pos;
            }
            n = n >> 1;
            pos++;
        }
        return maxGap;
    }
};

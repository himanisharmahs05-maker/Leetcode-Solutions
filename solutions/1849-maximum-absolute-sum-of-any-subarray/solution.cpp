class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxend=0, minend=0;
        int maxsum=0, minsum=0;

        for(int x : nums){
            maxend= max(x,maxend+x);
            maxsum=max(maxsum,maxend);

            minend=min(x,minend+x);
            minsum=min(minsum,minend);
        }
        return max(maxsum,abs(minsum));
        
    }
};

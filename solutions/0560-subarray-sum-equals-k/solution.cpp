class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int,int>f;
        int sum=0, res=0;
        f[0]=1;
         for(int x : nums) {
            sum += x;
            res += f[sum - k];
            f[sum]++;

        }
        return res;
        
    }
};

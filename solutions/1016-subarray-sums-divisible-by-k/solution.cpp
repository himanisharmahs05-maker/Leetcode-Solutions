class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int>f;
        int n=nums.size();
        int sum=0;
        int count=0;
        f[0]=1;

        for(int num : nums){
            sum+=num;

            int mod=sum%k;
            if(mod<0) mod+=k;

            count+=f[mod];
            f[mod]++;
        }
        return count;
            
        
    }
};

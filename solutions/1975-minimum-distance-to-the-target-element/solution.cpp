class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int mindist= INT_MAX;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                mindist= min(mindist, abs(i- start));
            }

        }
        return mindist;
        
    }
};

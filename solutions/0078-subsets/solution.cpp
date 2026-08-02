class Solution {
public:
    void solve(vector<int>&nums,int index, vector<int>&current, vector<vector<int>>&ans){
        if(index==nums.size()){
            ans.push_back(current);
            return;
        }
        //include
        current.push_back(nums[index]);
        solve(nums,index+1,current,ans);

        //backtrack
        current.pop_back();

        //dont include
        solve(nums,index+1,current,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>current;

        solve(nums,0,current,ans);
        return ans;
        
    }
};

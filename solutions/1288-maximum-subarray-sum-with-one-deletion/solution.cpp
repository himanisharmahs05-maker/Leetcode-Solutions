class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();

        int nodelete= arr[0];
        int onedelete = 0;
        int ans=arr[0];

        for(int i=1;i<n;i++){
            onedelete = max(onedelete + arr[i], nodelete);
            nodelete = max(arr[i], nodelete+arr[i]);

            ans=max({ans,nodelete,onedelete});
        }
        return ans;
    }
};

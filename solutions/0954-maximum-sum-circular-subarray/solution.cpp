class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int currMax = 0, maxSum = INT_MIN;

        int currMin = 0, minSum = INT_MAX;  


        for(int val:nums){
            currMax= max(val,currMax +val);
            maxSum=max(maxSum, currMax);

            currMin= min(val,currMin+val);
            minSum= min(minSum,currMin);

            totalSum +=val;

        }
        if (maxSum<0) return maxSum;
        return max(maxSum, totalSum- minSum);
        
    }
};

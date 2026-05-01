#include <vector>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        
        long long total_sum = 0;
        long long F = 0;
        
        // Calculate total sum and F(0)
        for (int i = 0; i < n; i++) {
            total_sum += nums[i];
            F += (long long)i * nums[i];
        }
        
        long long max_val = F;
        
        // Apply recurrence relation
        for (int k = 1; k < n; k++) {
            F = F + total_sum - (long long)n * nums[n - k];
            max_val = max(max_val, F);
        }
        
        return (int)max_val;
    }
};

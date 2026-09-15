class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();

        int satisfied = 0;

        for(int i = 0; i < n; i++) {
            if(grumpy[i] == 0) {
                satisfied += customers[i];
            }
        }

        
        int extra = 0;

        for(int i = 0; i < minutes; i++) {
            if(grumpy[i] == 1) {
                extra += customers[i];
            }
        }

        int maxExtra = extra;

       
        for(int right = minutes; right < n; right++) {

            
            if(grumpy[right] == 1) {
                extra += customers[right];
            }

           
            int left = right - minutes;

            if(grumpy[left] == 1) {
                extra -= customers[left];
            }

            maxExtra = max(maxExtra, extra);
        }

        return satisfied + maxExtra;
    }
};

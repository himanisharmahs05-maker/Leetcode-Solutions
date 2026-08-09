class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(),prices.rend());
        sort(discounts.rbegin(),discounts.rend());

        double answer=0;

        int m= min(prices.size(),discounts.size());

        for(int i=0;i<m;i++){
            answer+=(double)prices[i]* (100-discounts[i])/100.0;
        }
        for(int i=m;i<prices.size();i++){
            answer+=prices[i];
        }
        return answer;
        
    }
};

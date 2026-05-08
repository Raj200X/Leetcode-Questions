class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int minPrice = INT_MAX;
        for (int i = 0;i<prices.size();i++){
            if (prices[i]<minPrice){
                minPrice = prices[i];
            }
            if (prices[i]-minPrice>maxP){
                maxP = prices[i]-minPrice;
            }
        }
        return maxP;
    }
};
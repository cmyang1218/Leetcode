class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, minValue = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minValue) {
                minValue = prices[i];
            }else if (prices[i] - minValue > maxProfit) {
                maxProfit = prices[i] - minValue;
            }
        }
        return maxProfit;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minPrice = INT_MAX;  // Minimum price seen so far (buy)
        int maxProfit = 0;       // Maximum profit
        
        for(int i = 0; i < prices.size(); i++)
        {
            // Update minimum price (best day to buy so far)
            minPrice = min(minPrice, prices[i]);

            // Calculate profit if we sell today
            int profitToday = prices[i] - minPrice;

            // Update maximum profit
            maxProfit = max(maxProfit, profitToday);
        }

        return maxProfit;
    }
};
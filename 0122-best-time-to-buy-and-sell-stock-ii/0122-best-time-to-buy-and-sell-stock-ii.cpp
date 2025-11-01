class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Variable to store the total profit
        int profit = 0;

        // Traverse the prices array starting from the second day
        for (int i = 1; i < prices.size(); i++) {
            
            // If today's price is higher than yesterday's price,
            // it means we can earn profit by buying yesterday and selling today.
            if (prices[i] > prices[i - 1]) {
                // Add the difference to total profit
                profit += prices[i] - prices[i - 1];
            }
        }

        // Return the maximum profit after completing all transactions
        return profit;
    }
};

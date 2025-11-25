class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxProfit = 0;       // Stores the maximum profit found so far
        int minPrice = INT_MAX;  // Tracks the lowest price (best day to buy)

        // Traverse the price list once (O(n) time)
        for (auto& price : prices)
        {
            // Update the minimum price if today's price is lower
            // This ensures your "buy" always happens before the "sell"
            minPrice = min(minPrice, price);

            // Calculate profit if we sell today:
            // price - minPrice (best buy earlier, sell now)
            int profitToday = price - minPrice;

            // Update maximum profit if today's profit is higher
            maxProfit = max(maxProfit, profitToday);
        }

        // If no positive profit exists, answer remains 0
        return maxProfit;
    }
};

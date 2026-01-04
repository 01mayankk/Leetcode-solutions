class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // buy1  -> max profit after first buy
        // sell1 -> max profit after first sell
        // buy2  -> max profit after second buy
        // sell2 -> max profit after second sell

        int buy1 = INT_MIN, buy2 = INT_MIN;
        int sell1 = 0, sell2 = 0;

        // Traverse each day's stock price
        for (int price : prices) {

            // Maximum profit after first buy
            // Either keep previous buy or buy today
            buy1 = max(buy1, -price);

            // Maximum profit after first sell
            // Either keep previous sell or sell today
            sell1 = max(sell1, buy1 + price);

            // Maximum profit after second buy
            // Use profit from first sell to buy again
            buy2 = max(buy2, sell1 - price);

            // Maximum profit after second sell
            // Either keep previous sell or sell today
            sell2 = max(sell2, buy2 + price);
        }

        // Maximum profit after at most two transactions
        return sell2;
    }
};

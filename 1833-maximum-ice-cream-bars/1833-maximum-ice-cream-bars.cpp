class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        // Sort costs so that we buy the cheapest ice creams first
        sort(costs.begin(), costs.end());

        int sum = 0;  // Total coins spent so far
        int len = 0;  // Number of ice creams purchased

        for (int cost : costs) {

            // If current spending is still below available coins
            if (sum < coins) {
                sum += cost; // Buy current ice cream
                len++;
            }
            // Exact amount spent, cannot buy more
            else if (sum == coins) {
                return len;
            }

            // If coins exceeded after buying current ice cream,
            // undo the purchase and stop counting it
            if (sum > coins) {
                sum -= cost;
                len--;
                break;
            }
        }

        return len;
    }
};
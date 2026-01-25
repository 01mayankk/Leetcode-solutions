class Solution {
public:
    int minimumCost(vector<int>& cost) {

        // Sort candies in descending order
        // So that we always buy the most expensive candies first
        sort(cost.begin(), cost.end(), greater<int>());

        int count = 0;        // Counts how many candies have been bought in current group of 3
        int purchase = 0;     // Total amount spent

        // Traverse all candy prices
        for (int i = 0; i < cost.size(); i++) {

            // If two candies are already bought,
            // the third candy becomes free
            if (count == 2) {
                count = 0;    // Reset count for next group of 3
                continue;     // Skip adding price (free candy)
            }

            // Buy the candy and add its price
            purchase += cost[i];
            count++;
        }

        // Return minimum total cost
        return purchase;
    }
};

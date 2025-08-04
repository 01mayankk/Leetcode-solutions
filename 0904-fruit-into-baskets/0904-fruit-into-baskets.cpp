class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // 'start' is the beginning of the sliding window
        // 'maxLen' keeps track of the maximum number of fruits we can collect
        int start = 0, maxLen = 0;

        // HashMap to store the count of each type of fruit in the current window
        unordered_map<int, int> basket;

        // Iterate through each fruit using 'end' as the end of the sliding window
        for (int end = 0; end < fruits.size(); ++end) {
            // Add the current fruit to the basket (increase its count)
            basket[fruits[end]]++;

            // If there are more than 2 types of fruits in the basket, shrink the window from the start
            while (basket.size() > 2) {
                // Decrease the count of the fruit at the start of the window
                basket[fruits[start]]--;

                // If the count becomes 0, remove it from the basket
                if (basket[fruits[start]] == 0) {
                    basket.erase(fruits[start]);
                }

                // Move the start of the window forward
                start++;
            }

            // Update the maximum length of a valid window (with at most 2 fruit types)
            maxLen = max(maxLen, end - start + 1);
        }

        // Return the maximum number of fruits we can collect
        return maxLen;
    }
};

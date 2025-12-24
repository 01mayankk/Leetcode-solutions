class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {

        // Step 1: Calculate total number of apples
        int totalApples = 0;
        for (int a : apple)
            totalApples += a;

        // Step 2: Sort box capacities in descending order
        // So we use largest boxes first (greedy approach)
        sort(capacity.begin(), capacity.end(), greater<int>());

        int currCapacity = 0; // Tracks total capacity used so far
        int boxes = 0;        // Counts number of boxes used

        // Step 3: Add boxes until capacity can hold all apples
        for (int c : capacity) {
            currCapacity += c; // Add current box capacity
            boxes++;           // One more box used

            // If total capacity is enough to store all apples, stop
            if (currCapacity >= totalApples)
                return boxes;
        }

        // Guaranteed by constraints that a solution exists
        return boxes;
    }
};

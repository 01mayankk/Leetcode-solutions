class Solution {
public:
    int minElement(vector<int>& nums) {
        
        // Stores the minimum digit sum found so far
        int minValue = INT_MAX;

        // Traverse each number in the array
        for(auto& num : nums)
        {
            int copy = num;  // Create a copy to preserve original number
            int sum = 0;     // Stores digit sum of current number

            // Calculate sum of digits
            while(copy > 0)
            {
                int digit = copy % 10; // Extract last digit
                sum += digit;          // Add digit to sum
                copy /= 10;            // Remove last digit
            }

            // Update minimum digit sum
            minValue = min(sum, minValue);
        }

        return minValue;
    }
};
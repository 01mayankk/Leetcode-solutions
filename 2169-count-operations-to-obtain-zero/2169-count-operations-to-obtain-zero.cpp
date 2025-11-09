class Solution {
public:
    int countOperations(int num1, int num2) {
        
        int count = 0; // Initialize operation counter

        // Continue until one of the numbers becomes 0
        while (num1 != 0 && num2 != 0)
        {
            // If num1 is smaller or equal, subtract it from num2
            if (num1 <= num2)
            {
                num2 = num2 - num1;
            }
            // Otherwise, subtract num2 from num1
            else
            {
                num1 = num1 - num2;
            }

            // Increment operation count for each subtraction performed
            count += 1;
        }

        // Once either number becomes 0, return total operation count
        return count;
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        int sum = 0;

        // Calculate the total sum of the array
        for(int x : nums) {
            sum += x; 
        }

        /*
            We want the array sum to be divisible by k.

            Let r = sum % k  (remainder)
            - If r == 0 → already divisible → no operation needed → return 0
            - Otherwise, we need to decrease elements total by exactly r
              because each operation subtracts 1 from the sum.

            Therefore, minimum operations required = r
        */

        return sum % k;
    }
};

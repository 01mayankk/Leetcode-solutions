class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        // Iterate over all numbers in the array
        for (int n : nums) {
            int count = 0;   // Count of divisors
            int sum = 0;     // Sum of divisors

            // Check divisors up to sqrt(n)
            for (int i = 1; i * i <= n; i++) {
                if (n % i == 0) {
                    int d1 = i;
                    int d2 = n / i;

                    // If both divisors are same (perfect square)
                    if (d1 == d2) {
                        count += 1;
                        sum += d1;
                    }
                    // Two different divisors
                    else {
                        count += 2;
                        sum += (d1 + d2);
                    }

                    // No need to continue if more than 4 divisors
                    if (count > 4)
                        break;
                }
            }

            // Add to answer only if exactly 4 divisors
            if (count == 4)
                ans += sum;
        }

        return ans;
    }
};

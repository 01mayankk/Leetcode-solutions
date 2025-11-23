class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {

        int sum = 0;

        // rem1 → numbers giving remainder 1 when divided by 3
        // rem2 → numbers giving remainder 2 when divided by 3
        vector<int> rem1, rem2;

        // Step 1: Calculate total sum and gather numbers by remainders
        for (int x : nums) {
            sum += x;

            if (x % 3 == 1) 
                rem1.push_back(x);
            else if (x % 3 == 2) 
                rem2.push_back(x);
        }

        // Step 2: Sort both remainder groups to easily pick smallest numbers to remove
        sort(rem1.begin(), rem1.end());
        sort(rem2.begin(), rem2.end());

        // Step 3: If total sum is already divisible by 3, return it directly
        if (sum % 3 == 0) 
            return sum;

        int ans = 0;

        // Case 1: sum % 3 == 1 → Need to remove remainder 1 from sum
        // Options:
        //   (a) remove one smallest number with remainder 1
        //   (b) OR remove two smallest numbers with remainder 2
        if (sum % 3 == 1) {

            // Option A: Remove smallest rem1 number (if exists)
            int remove1 = rem1.size() >= 1 ? rem1[0] : INT_MAX;

            // Option B: Remove two smallest rem2 numbers (if exist)
            int remove2 = rem2.size() >= 2 ? rem2[0] + rem2[1] : INT_MAX;

            // Choose the removal that keeps sum maximum
            ans = sum - min(remove1, remove2);
        }

        // Case 2: sum % 3 == 2 → Need to remove remainder 2 from sum
        // Options:
        //   (a) remove one smallest number with remainder 2
        //   (b) OR remove two smallest numbers with remainder 1
        else { 
            // Option A: Remove smallest rem2 number
            int remove1 = rem2.size() >= 1 ? rem2[0] : INT_MAX;

            // Option B: Remove two smallest rem1 numbers
            int remove2 = rem1.size() >= 2 ? rem1[0] + rem1[1] : INT_MAX;

            // Choose the cheapest removal
            ans = sum - min(remove1, remove2);
        }

        // If no valid removal is possible (shouldn't happen), return 0
        return ans < 0 ? 0 : ans;
    }
};

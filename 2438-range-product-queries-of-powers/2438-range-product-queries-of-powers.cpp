class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long> p2;   // Stores the powers of 2 present in the binary representation of n
        vector<int> res;   // Stores the result for each query
        int mod = 1e9+7;   // Modulo value to prevent overflow (common in large product problems)
        int i = 0;         // Bit position index

        // Step 1: Extract the powers of 2 from binary representation of n
        while (n) {
            if (n & 1) {
                // If the current bit is set, store the actual power of 2 (2^i)
                // (1L << i) shifts '1' left by i bits = 2^i
                p2.push_back(1L << i);
            }
            n >>= 1; // Shift bits of n to the right (move to next bit)
            i++;     // Increment bit position
        }

        // Step 2: Process each query
        for (auto &q : queries) {
            long long prod = 1; // Product for current query (use long long to avoid overflow before mod)
            
            // Multiply all powers of 2 in the range [q[0], q[1]] from p2
            for (int j = q[0]; j <= q[1]; j++) {
                prod = (prod * p2[j]) % mod; // Keep taking mod to prevent overflow
            }
            
            // Store the final product for this query
            res.push_back(prod);
        }

        // Step 3: Return all query results
        return res;
    }
};

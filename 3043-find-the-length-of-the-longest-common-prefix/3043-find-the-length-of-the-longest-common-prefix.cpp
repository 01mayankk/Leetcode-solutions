class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        // Set to store all prefixes generated from arr1
        unordered_set<string> prefixes;

        // Traverse every number in arr1
        for (int num : arr1) {

            // Convert integer to string
            string s = to_string(num);

            // Variable to build prefixes step by step
            string prefix = "";

            // Generate all prefixes of current number
            for (char ch : s) {

                // Add current digit to prefix
                prefix += ch;

                // Store prefix in hash set
                prefixes.insert(prefix);
            }
        }

        // Variable to store maximum common prefix length
        int ans = 0;

        // Traverse every number in arr2
        for (int num : arr2) {

            // Convert integer to string
            string s = to_string(num);

            // Variable to build prefixes
            string prefix = "";

            // Generate prefixes one by one
            for (char ch : s) {

                // Add current digit to prefix
                prefix += ch;

                // Check if this prefix exists in arr1 prefixes
                if (prefixes.count(prefix)) {

                    // Update maximum prefix length found so far
                    ans = max(ans, (int)prefix.length());
                }
            }
        }

        // Return longest common prefix length
        return ans;
    }
};
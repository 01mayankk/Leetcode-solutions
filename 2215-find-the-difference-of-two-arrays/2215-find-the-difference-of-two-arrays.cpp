class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // Step 1: Store all unique elements of nums1 in set s1
        unordered_set<int> s1(nums1.begin(), nums1.end());
        
        // Step 2: Store all unique elements of nums2 in set s2
        unordered_set<int> s2(nums2.begin(), nums2.end());

        // Vectors to store elements that are unique to each array
        vector<int> diff1, diff2;

        // Step 3: Find elements present in s1 but NOT in s2
        for (int x : s1) {
            if (!s2.count(x)) {   // if x not found in s2
                diff1.push_back(x);
            }
        }

        // Step 4: Find elements present in s2 but NOT in s1
        for (int x : s2) {
            if (!s1.count(x)) {   // if x not found in s1
                diff2.push_back(x);
            }
        }

        // Step 5: Return result as a 2D vector
        // First vector = unique elements from nums1
        // Second vector = unique elements from nums2
        return {diff1, diff2};
    }
};

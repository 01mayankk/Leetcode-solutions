class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // Create multisets from both arrays
        // multiset allows duplicate values and stores them in sorted order
        multiset<int> ms1(nums1.begin(), nums1.end());
        multiset<int> ms2(nums2.begin(), nums2.end());

        vector<int> result; // to store intersection elements

        // For efficiency, always iterate over the smaller multiset
        // This reduces the number of find/erase operations
        if (ms1.size() > ms2.size()) 
            swap(ms1, ms2);

        // Iterate through all elements of the smaller multiset
        for (int num : ms1) {
            // Check if current number exists in the second multiset
            auto it = ms2.find(num);

            if (it != ms2.end()) {
                // If found, add it to the result (one occurrence)
                result.push_back(num);

                // Remove that occurrence from ms2
                // to handle duplicates correctly (avoid counting same element twice)
                ms2.erase(it);
            }
        }

        // Return the final intersection vector
        return result;
    }
};


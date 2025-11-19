class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {

        // Put all elements of nums into an unordered_set
        // This allows O(1) average-time lookup for checking if a value exists.
        unordered_set<int> s(nums.begin(), nums.end());

        // As long as the current value of 'original' exists in the set,
        // multiply it by 2. Keep repeating until it's no longer found.
        while (s.count(original)) {
            original *= 2;  // double the value
        }

        // Once 'original' is not in the set, return it.
        return original;
    }
};

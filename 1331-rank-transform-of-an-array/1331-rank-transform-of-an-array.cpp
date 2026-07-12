class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        // Create a copy so that the original array remains unchanged.
        vector<int> copy(arr.begin(), arr.end());

        // Sort the copied array.
        sort(copy.begin(), copy.end());

        // Map each unique value to its rank.
        unordered_map<int, int> rankMap;
        int rank = 1;

        for (int i = 0; i < copy.size(); i++) {

            // Assign rank only if this value hasn't been seen before.
            if (rankMap.find(copy[i]) == rankMap.end()) {
                rankMap[copy[i]] = rank;
                rank++;
            }
        }

        // Store the ranked values.
        vector<int> result(arr.size());

        for (int i = 0; i < arr.size(); i++) {

            // Every element already exists in the map.
            result[i] = rankMap[arr[i]];
        }

        return result;
    }
};
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";

        // Process each word
        for (string &word : words) {
            int sum = 0;

            // Calculate weight of the current word
            for (char ch : word) {
                sum += weights[ch - 'a'];
            }

            // Take modulo 26
            int rem = sum % 26;

            // Reverse mapping:
            // 0 -> z, 1 -> y, ..., 25 -> a
            char mappedChar = 'z' - rem;

            result += mappedChar;
        }

        return result;
    }
};
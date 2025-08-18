class Solution {
    const double EPS = 1e-6;  // Tolerance for floating-point comparison

public:
    // Main function: checks if we can make 24 from given 4 cards
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        // Convert input integers to doubles (important for division operations)
        for (int n : cards) nums.push_back((double)n);
        return dfs(nums);  // Start recursive search
    }

private:
    // Recursive DFS: try all possible ways to combine numbers
    bool dfs(vector<double>& nums) {
        // Base case: if only one number left, check if it's close to 24
        if (nums.size() == 1) {
            return fabs(nums[0] - 24.0) < EPS;
        }

        // Try all pairs of numbers (i, j)
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j) continue;  // Can't use same number twice

                // Prepare the "next state" after combining nums[i] and nums[j]
                vector<double> next;
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j) next.push_back(nums[k]);
                }

                // Try all possible results of combining nums[i] and nums[j]
                for (double val : compute(nums[i], nums[j])) {
                    next.push_back(val);   // Add the result to the remaining numbers
                    if (dfs(next)) return true;  // Recurse
                    next.pop_back();       // Backtrack
                }
            }
        }
        return false;  // No valid combination found
    }

    // Compute all possible results from combining a and b
    vector<double> compute(double a, double b) {
        vector<double> res;
        res.push_back(a + b);      // Addition
        res.push_back(a - b);      // Subtraction (a - b)
        res.push_back(b - a);      // Subtraction (b - a)
        res.push_back(a * b);      // Multiplication
        if (fabs(b) > EPS) res.push_back(a / b);  // Division (a / b), avoid divide by zero
        if (fabs(a) > EPS) res.push_back(b / a);  // Division (b / a)
        return res;
    }
};

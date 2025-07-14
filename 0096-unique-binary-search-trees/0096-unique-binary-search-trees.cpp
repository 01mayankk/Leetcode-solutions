#include <cmath>  // for tgamma
class Solution {
public:
    int numTrees(int n) {
        // Catalan number: C(n) = (2n)! / (n+1)! * n!
        // Use tgamma(n+1) == n!

        double numerator = tgamma(2*n + 1);     
        double denominator = tgamma(n + 2) * tgamma(n + 1);  

        return static_cast<int>(numerator / denominator + 0.5);  // round to nearest int
    }
};

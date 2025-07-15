// #include <cmath>      
// class Solution {
// public:
//     int numTrees(int n) {
//         // Catalan number: C(n) = (2n)! / (n+1)! * n!
//         // Use tgamma(n+1) == n!

//         double numerator = tgamma(2*n + 1);     
//         double denominator = tgamma(n + 2) * tgamma(n + 1);  

//         return static_cast<int>(numerator / denominator + 0.5);  // round to nearest int
//     }
// };



// //we can also go for boost::multiprecision 
// // there we can define a variable using cpp_int variablename;
// //then calculate the value as it will safely return the factorial till n > 20;
class Solution {
public:
    int numTrees(int n) {
        if (n <= 1)
            return 1;

        int total = 0;
        for (int i = 1; i <= n; ++i) {
            int left = numTrees(i - 1);
            int right = numTrees(n - i);
            total += left * right;
        }
        return total;
    }
};


//above method is done using recursion 

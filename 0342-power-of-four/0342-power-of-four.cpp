#include<bit>
class Solution {
public:
    bool isPowerOfFour(int n) {

        return n > 0 && (n & (n - 1)) == 0 && (n % 3 == 1);   
        //Here first n > 0 means number is positive;
        // n & ( n - 1) it will make zero all bit places where the bit is zero

        //Only power of 4 gives n % 3 == 1 for ex 16 % 3 = 1 yes it is power of 4 but at same time 8 % 3 == 2 which is not the power of 4.
        //we can also count the trialing zeros as power  of 4 number always have trailing zeroes;
        
    }
};
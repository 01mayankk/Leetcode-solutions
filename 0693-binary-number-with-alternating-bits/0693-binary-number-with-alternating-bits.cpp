// class Solution { //This approach is fine just the constraint is 2^31 so adding +1 will be overflow from max capacity of int.
// public:
//     bool hasAlternatingBits(int n) {
        
//         // Step 1:
//         // Shift n right by 1 bit and XOR with original number.
//         // If bits are alternating, XOR will produce all 1s.
//         //
//         // Example:
//         // n        = 1010  (10)
//         // n >> 1   = 0101  (5)
//         // XOR      = 1111  (all 1s)
        
//         int x = n ^ (n >> 1);
        
        
//         // Step 2:
//         // Check if x is of the form 11111... (all 1s).
//         //
//         // Property:
//         // If a number is all 1s in binary:
//         //    1111
//         // then:
//         //    1111 & (1111 + 1)
//         //    1111 & 10000 = 0
//         //
//         // So for numbers that are all 1s:
//         //     x & (x + 1) == 0
        
//         return (x & (x + 1)) == 0;
//     }
// };

class Solution {
public:
    bool hasAlternatingBits(int n) {

        /*
         Step 1: XOR the number with itself right-shifted by 1.

         If bits in n are alternating, then:
         
             n        = 101010
             n >> 1   = 010101
             ------------------
             XOR      = 111111   (all 1s)

         So if n has alternating bits, 
         x = n ^ (n >> 1) will produce a number that has all bits as 1.
        */

        unsigned int x = n ^ (n >> 1);

        /*
         Step 2: Check if x is of the form 111... (all 1s).

         Property:
            A number made entirely of 1s (like 1, 3, 7, 15, 31...)

            Example:
                1111   (15)
              +    1
              --------
               10000

            Now:
                1111
              &10000
              --------
                0000

         So:
            x & (x + 1) == 0

         This condition is true ONLY if x is of the form 111...
        */

        return (x & (x + 1)) == 0;
    }
};

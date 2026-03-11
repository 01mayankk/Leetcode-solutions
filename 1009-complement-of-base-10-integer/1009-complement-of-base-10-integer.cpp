class Solution {
public:
    int bitwiseComplement(int n) {
        
        // Special case: complement of 0 is 1
        if(n == 0) 
            return 1;
        
        int mask = 0;
        int temp = n;
        
        // Create mask with same number of bits as n
        while(temp > 0)
        {
            mask = (mask << 1) | 1; // add 1 bit
            temp >>= 1;
        }
        
        // XOR with mask to flip bits
        return n ^ mask;
    }
};
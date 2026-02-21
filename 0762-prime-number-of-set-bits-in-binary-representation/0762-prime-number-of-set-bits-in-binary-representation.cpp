class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        
        int prime = 0;  // stores count of numbers whose set bits are prime
        
        // Traverse through each number in given range
        for(int num = left; num <= right; num++)
        {
            // Convert number to 32-bit binary representation
            bitset<32> bi(num);
            
            // Count number of set bits (1s) in binary form
            int count = bi.count();
            
            // Prime numbers start from 2
            // If set bits are 0 or 1, skip
            if(count < 2) continue;
            
            bool isPrime = true;  // Assume prime initially
            
            // Check if 'count' is prime
            // Only check till sqrt(count) for efficiency
            for(int i = 2; i * i <= count; i++)
            {
                // If divisible by any number → not prime
                if(count % i == 0)
                {
                    isPrime = false;
                    break;  // No need to check further
                }
            }
            
            // If set bit count is prime, increment result
            if(isPrime)
            {
                prime++;
            }
        }
        
        return prime;  // Return total count
    }
};
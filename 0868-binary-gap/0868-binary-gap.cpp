class Solution {
public:
    int binaryGap(int n) {
        
        // This will store the index (bit position) of the previous '1'
        // Initialize with -1 meaning we haven't seen any '1' yet
        int lastIndex = -1;     
        
        // This will store the maximum distance between consecutive 1s
        int maxDistance = 0;    
        
        // This keeps track of the current bit position (0-based index)
        int currentIndex = 0;   
        
        // Traverse all bits of n until it becomes 0
        while(n > 0) {
            
            // Check if the least significant bit (LSB) is 1
            // (n & 1) gives 1 if last bit is 1, otherwise 0
            if(n & 1) {
                
                // If this is NOT the first '1' we encountered
                if(lastIndex != -1) {
                    
                    // Calculate distance between current 1 and previous 1
                    // Update maxDistance if this gap is larger
                    maxDistance = max(maxDistance, currentIndex - lastIndex);
                }
                
                // Update lastIndex to current position of '1'
                lastIndex = currentIndex;
            }
            
            // Right shift n by 1 to move to next bit
            // This effectively removes the last bit
            n = n >> 1; 
            
            // Move to next bit position
            currentIndex++;
        }
        
        // Return the maximum gap found
        return maxDistance;
    }
};
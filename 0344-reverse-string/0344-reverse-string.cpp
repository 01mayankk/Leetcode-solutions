class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int left = 0;
        int right = s.size() - 1;

        // Two-pointer approach:
        // Swap characters from both ends and move inward
        while(left < right)
        {
            // Swap current pair
            swap(s[left], s[right]);
            
            // Move pointers towards the center
            left++;
            right--;
        }
    }
};

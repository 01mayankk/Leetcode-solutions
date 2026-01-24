class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        
        // Iterate through each word in the list
        for (string& word : words) {
            
            int left = 0;                     // Pointer at the start of the word
            int right = word.size() - 1;      // Pointer at the end of the word
            bool isPalindrome = true;         // Assume the word is a palindrome
            
            // Check the word using the two-pointer technique
            while (left < right) {
                
                // If characters at both ends are different,
                // the word is not a palindrome
                if (word[left] != word[right]) {
                    isPalindrome = false;
                    break;                   // Stop checking this word
                }
                
                // Move pointers towards the center
                left++;
                right--;
            }
            
            // If the current word is a palindrome,
            // return it immediately (first one found)
            if (isPalindrome) {
                return word;
            }
        }
        
        // If no palindromic word exists, return empty string
        return "";
    }
};

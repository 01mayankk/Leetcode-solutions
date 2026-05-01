class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        // If ransomNote is longer, it's impossible to construct
        // because we don't have enough total characters
        if (ransomNote.size() > magazine.size()) {
            return false;
        }

        // Hash map to store frequency of each character in magazine
        unordered_map<char, int> freq;

        // Step 1: Count available characters from magazine
        for (char ch : magazine) {
            freq[ch]++;  // increase count of current character
        }

        // Step 2: Try to "use" characters for ransomNote
        for (char ch : ransomNote) {
            
            // Decrease frequency first (consume character)
            // If character does not exist, it defaults to 0 → becomes -1
            freq[ch]--;

            // If frequency goes negative, it means:
            // we needed more of this character than available
            if (freq[ch] < 0) {
                return false;
            }
        }

        // If all characters were successfully used
        return true;
    }
};
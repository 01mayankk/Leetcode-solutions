class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        // sort() takes:
        // 1. Starting iterator
        // 2. Ending iterator
        // 3. Custom comparator function (lambda here)
        sort(arr.begin(), arr.end(), [](int a, int b){
            
            // Count number of set bits (1s) in binary representation
            // __builtin_popcount(x) is a GCC inbuilt function
            int countA = __builtin_popcount(a);
            int countB = __builtin_popcount(b);
            
            // If both numbers have same number of set bits
            // then sort them normally in ascending order
            if(countA == countB)
                return a < b;
            
            // Otherwise, the number with fewer set bits comes first
            return countA < countB;
        });
        
        // Return the sorted array
        return arr;
    }
};
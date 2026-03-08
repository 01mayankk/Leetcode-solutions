class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        
        int n = nums.size();
        string result = "";
        
        // Build a new string using diagonal flipping
        for(int i = 0; i < n; i++)
        {
            // If the ith string has '0' at ith position,
            // put '1' in our result, otherwise put '0'
            if(nums[i][i] == '0')
                result += '1';
            else
                result += '0';
        }
        
        // This guarantees the string is different
        // from every string in nums
        return result;
    }
};
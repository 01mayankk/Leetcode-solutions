class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int left = 0;
        int right = nums.size() - 1;

        // Binary Search
        while(left < right) {
            
            int mid = left + (right - left) / 2;

            // If middle element is smaller than right,
            // minimum lies in left half including mid
            if(nums[mid] < nums[right]) {
                right = mid;
            }
            // If middle element is greater than right,
            // minimum lies in right half excluding mid
            else if(nums[mid] > nums[right]) {
                left = mid + 1;
            }
            // Duplicate case:
            // We cannot determine the side,
            // so safely reduce right by 1
            else {
                right--;
            }
        }

        // left == right -> minimum element index
        return nums[left];
    }
};
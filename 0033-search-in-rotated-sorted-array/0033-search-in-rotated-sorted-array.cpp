class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int start = 0;
        int end = nums.size() - 1;

        while(start <= end)
        {
            int mid = start + (end - start) / 2;

            // If target found, return index immediately
            if(nums[mid] == target) 
                return mid;

            /*
                The array is rotated, so one of the two halves is always sorted.
                
                Example:
                [4,5,6,7,0,1,2]
                 L     M     R

                Left half  [4,5,6,7] sorted
                Right half [0,1,2]   sorted

                We check which side is sorted by comparing start & mid.
            */

            // 🔹 CASE 1: Left half is sorted
            if(nums[start] <= nums[mid]) 
            {
                /*  
                    If target lies inside this sorted left half,
                    it must be within range [start, mid-1]:

                    Example:
                    nums = [4,5,6,7,0,1,2], target=6
                    sorted left half = [4,5,6,7]
                    4 <= 6 < 7   → target is inside left range
                */
                if(nums[start] <= target && target < nums[mid])
                    end = mid - 1;    // move search space to left sorted zone
                else
                    start = mid + 1;  // target is not in left → search right side
            }

            // 🔹 CASE 2: Right half is sorted
            else 
            {
                /*
                    If left side is not sorted → right side must be sorted.

                    Example:
                    nums = [6,7,0,1,2,3,4]
                               M       R
                    Sorted right half = [0,1,2,3,4]
                */

                // If target lies inside sorted right half
                if(nums[mid] < target && target <= nums[end])
                    start = mid + 1;  // search inside right half
                else
                    end = mid - 1;    // otherwise it lies in left unsorted region
            }
        }

        // If not found anywhere → return -1
        return -1;
    }
};

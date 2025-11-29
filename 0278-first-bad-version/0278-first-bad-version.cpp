// The API isBadVersion(int version) is already provided by LeetCode.
// It returns true if the version is bad, false if it is good.

class Solution {
public:
    int firstBadVersion(int n) {
        
        int start = 1;     // search space start
        int end = n;       // search space end

        // We use binary search to minimize calls to isBadVersion()
        // because once a version is bad → all versions after it are bad too.

        while(start < end)
        {
            int mid = start + (end - start) / 2; 
            // (using this instead of (start+end)/2 to prevent integer overflow)

            /*
                If mid is a bad version:
                ---------------------------------
                That means:
                    - mid might be the FIRST bad version
                    - OR there might be a bad version BEFORE mid

                Example: 1 2 3 4 5
                           G G B B B   (G = good, B = bad)
                              ↑
                             mid = 3 (bad)
                3 is bad, but maybe 2 is also bad? We don't know yet.

                So we shrink the search space to the LEFT side
                including mid → end = mid
            */
            if(isBadVersion(mid))
            {
                end = mid;  // look left side (including mid)
            }
            else
            {
                /*
                    If mid is NOT bad:
                    ---------------------------------
                    That means:
                        - All versions up to mid are GOOD
                        - So the first bad version must be AFTER mid

                    Example: 1 2 3 4 5
                               G G G B B
                         mid = 3 (good)
                    First bad cannot be 1,2,3 → so search right half.

                    We move start to mid + 1
                */
                start = mid + 1;
            }
        }

        // When start == end, we have narrowed down to one possible version,
        // and that is the FIRST bad version.
        return start;  // or return end, both are same here.
    }
};

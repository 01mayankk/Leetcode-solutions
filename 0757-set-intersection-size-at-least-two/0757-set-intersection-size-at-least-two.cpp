class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {

        /* 
           STEP 1: Sort intervals in a special greedy order:
           
           - Primary key: end in ASCENDING order  
             (intervals ending earlier must be processed first)
           
           - Secondary key: start in DESCENDING order  
             (for same end, longer interval first to avoid conflict)
        */
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b){
                 if (a[1] == b[1]) 
                     return a[0] > b[0]; // larger start first
                 return a[1] < b[1];     // smaller end first
             });

        // 'a' and 'b' represent the two largest chosen points so far.
        // a = largest selected number
        // b = second largest selected number
        // Initially, no numbers selected → use -1
        int a = -1, b = -1;

        // Total count of elements added to the set S
        int ans = 0;

        // Process each interval in greedy sorted order
        for (auto &I : intervals) {
            int start = I[0];
            int end   = I[1];

            // Check if the currently selected numbers lie inside this interval
            bool hasA = (a >= start);  // is 'a' inside the interval?
            bool hasB = (b >= start);  // is 'b' inside the interval?

            /* 
               CASE 1: Both a and b are already inside [start, end].
               That means we already have 2 points inside this interval.
               → NO need to add anything.
            */
            if (hasA && hasB) {
                continue;
            }

            /*
               CASE 2: Only 'a' is inside, but not 'b'
               We have exactly 1 point inside.
               → Need to add 1 more point.
               The best greedy point to add is the interval's endpoint 'end'.
               
               Why choose 'end'?
               Because higher numbers help satisfy future intervals.
            */
            else if (hasA) {
                // Promote old 'a' to 'b'
                b = a;
                // Add new largest number 'end'
                a = end;
                ans += 1; // added one number
            }

            /*
               CASE 3: Neither 'a' nor 'b' is inside this interval.
               We have 0 points inside.
               → Need to add 2 points.
               
               Greedy choice:
               - Add end-1
               - Add end
               
               Picking two largest possible ensures maximum chance
               to satisfy upcoming intervals without extra additions.
            */
            else {
                b = end - 1;
                a = end;
                ans += 2; // added two numbers
            }
        }

        // Return total size of the minimum set S
        return ans;
    }
};

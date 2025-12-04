class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int i = 0, j = n - 1;

        // ------------------------------------------------------------
        // STEP 1: Ignore all leading 'L'
        //
        // Any car moving left at the very beginning has no car to collide with.
        // Example: L L L R S R
        // These first L's will freely exit without any collision.
        // ------------------------------------------------------------
        while (i < n && directions[i] == 'L')
            i++;

        // ------------------------------------------------------------
        // STEP 2: Ignore all trailing 'R'
        //
        // Any car moving right at the very end also has no car to crash into.
        // Example: L S R R R   <- these R's leave safely
        // ------------------------------------------------------------
        while (j >= 0 && directions[j] == 'R')
            j--;

        // ------------------------------------------------------------
        // STEP 3: Count collisions in the remaining middle part
        //
        // After removing leading L and trailing R:
        // - Any 'R' or 'L' inside must eventually collide
        // - Only 'S' remains collision-free
        //
        // So simply count how many characters are NOT 'S'
        // ------------------------------------------------------------
        int collisions = 0;
        for (int k = i; k <= j; k++) {
            if (directions[k] != 'S')
                collisions++;
        }

        return collisions;
    }
};

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {

        // Sort asteroids in ascending order
        // so that we always try to absorb the smallest asteroid first.
        sort(asteroids.begin(), asteroids.end());

        // Use long long because mass can grow very large
        long long currentMass = mass;

        // Traverse all asteroids
        for (int asteroid : asteroids) {

            // If current mass is smaller than the asteroid,
            // we cannot destroy it.
            if (currentMass < asteroid)
                return false;

            // Destroy the asteroid and gain its mass
            currentMass += asteroid;
        }

        // All asteroids were destroyed successfully
        return true;
    }
};
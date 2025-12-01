class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        
        long long total = 0;
        // Calculate total battery power available
        for (long long b : batteries) 
            total += b;

        // Maximum possible equal running time cannot exceed total/n
        long long low = 0, high = total / n; 
        long long ans = 0;

        // Lambda function to check if we can run all 'n' computers for 'mid' time
        auto canRun = [&](long long mid) {
            long long power = 0;

            // Each battery contributes at most 'mid' time 
            // i.e. if battery[i] >= mid → it just contributes 'mid'
            // otherwise contributes battery[i]
            for (long long b : batteries) 
                power += min(b, mid); 

            // If total usable power >= n * mid → running time mid is possible
            return power >= mid * n;        
        };

        // Binary Search to find maximum 'T' for which canRun(T) = true
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (canRun(mid)) {
                ans = mid;        // mid is valid → try longer time
                low = mid + 1;    
            } 
            else {
                high = mid - 1;   // mid is too large → reduce
            }
        }

        return ans;   // maximum achievable equal running time
    }
};

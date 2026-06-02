class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        
        int n = landStartTime.size();
        int m = waterStartTime.size();

        int answer = INT_MAX;

        // Try every pair of land ride and water ride
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // -------------------------------------------------
                // Option 1: Land ride -> Water ride
                // -------------------------------------------------

                // Start land ride at its opening time
                int landFinish = landStartTime[i] + landDuration[i];

                // Water ride can start only after:
                // 1. Land ride finishes
                // 2. Water ride is open
                int waterStart = max(landFinish, waterStartTime[j]);

                // Final completion time for this order
                int finish1 = waterStart + waterDuration[j];

                // -------------------------------------------------
                // Option 2: Water ride -> Land ride
                // -------------------------------------------------

                // Start water ride at its opening time
                int waterFinish = waterStartTime[j] + waterDuration[j];

                // Land ride can start only after:
                // 1. Water ride finishes
                // 2. Land ride is open
                int landStart = max(waterFinish, landStartTime[i]);

                // Final completion time for this order
                int finish2 = landStart + landDuration[i];

                // Update answer with the best possible finish time
                answer = min(answer, min(finish1, finish2));
            }
        }

        return answer;
    }
};
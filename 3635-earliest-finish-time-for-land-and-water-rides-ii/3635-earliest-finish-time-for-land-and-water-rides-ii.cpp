class Solution {
public:

    /*
        Data structure to efficiently answer:

        min( max(t, start[i]) + duration[i] )

        Meaning:
        If we finish the first ride at time t,
        what is the earliest possible finishing time
        after taking one ride from the other category?
    */
    class RideQuery {
    public:
        vector<int> start;                     // sorted start times
        vector<long long> prefMinDuration;     // minimum duration till index i
        vector<long long> suffMinStartPlusDur; // minimum (start + duration) from i to end
        int n;

        RideQuery(vector<int>& startTime, vector<int>& duration) {
            n = startTime.size();

            // Store rides as (startTime, duration)
            vector<pair<int, int>> rides;

            for (int i = 0; i < n; i++) {
                rides.push_back({startTime[i], duration[i]});
            }

            // Sort rides by start time
            sort(rides.begin(), rides.end());

            start.resize(n);
            prefMinDuration.resize(n);

            // Extra position to avoid boundary checks
            suffMinStartPlusDur.resize(n + 1, (long long)4e18);

            // Build prefix minimum duration
            for (int i = 0; i < n; i++) {
                start[i] = rides[i].first;

                if (i == 0)
                    prefMinDuration[i] = rides[i].second;
                else
                    prefMinDuration[i] =
                        min(prefMinDuration[i - 1],
                            (long long)rides[i].second);
            }

            // Build suffix minimum of (start + duration)
            for (int i = n - 1; i >= 0; i--) {
                long long value =
                    (long long)rides[i].first + rides[i].second;

                suffMinStartPlusDur[i] =
                    min(suffMinStartPlusDur[i + 1], value);
            }
        }

        /*
            Query for a given finish time t.

            We want:

            min( max(t, start[i]) + duration[i] )
        */
        long long query(long long t) {

            long long ans = (long long)4e18;

            /*
                Find last ride whose start time <= t.

                Rides [0 ... idx] are already open.
                Rides [idx+1 ... n-1] open later.
            */
            int idx =
                upper_bound(start.begin(), start.end(), t)
                - start.begin() - 1;

            /*
                Case 1:
                Ride already open (start <= t)

                Start immediately at time t.

                Finish = t + duration

                We need minimum duration among all rides
                with start <= t.
            */
            if (idx >= 0) {
                ans = min(ans, t + prefMinDuration[idx]);
            }

            /*
                Case 2:
                Ride opens after time t (start > t)

                Need to wait until ride opens.

                Finish = start + duration

                We need minimum (start + duration)
                among all rides with start > t.
            */
            ans = min(ans, suffMinStartPlusDur[idx + 1]);

            return ans;
        }
    };

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        /*
            Data structure for water rides.

            After finishing a land ride,
            we'll query the best water ride.
        */
        RideQuery waterDS(waterStartTime, waterDuration);

        /*
            Data structure for land rides.

            After finishing a water ride,
            we'll query the best land ride.
        */
        RideQuery landDS(landStartTime, landDuration);

        long long answer = (long long)4e18;

        // --------------------------------------------------
        // Option 1 : Land Ride -> Water Ride
        // --------------------------------------------------
        for (int i = 0; i < n; i++) {

            // Finish time of current land ride
            long long landFinish =
                (long long)landStartTime[i] + landDuration[i];

            // Earliest finish time after taking a water ride
            answer = min(answer, waterDS.query(landFinish));
        }

        // --------------------------------------------------
        // Option 2 : Water Ride -> Land Ride
        // --------------------------------------------------
        for (int j = 0; j < m; j++) {

            // Finish time of current water ride
            long long waterFinish =
                (long long)waterStartTime[j] + waterDuration[j];

            // Earliest finish time after taking a land ride
            answer = min(answer, landDS.query(waterFinish));
        }

        return (int)answer;
    }
};
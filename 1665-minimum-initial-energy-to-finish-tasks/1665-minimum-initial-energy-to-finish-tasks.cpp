class Solution {
public:

    int minimumEffort(vector<vector<int>>& tasks) {

        /*
            Each task is represented as:
            tasks[i] = [actual, minimum]

            actual  -> energy consumed after completing the task
            minimum -> minimum energy required before starting the task

            Greedy Strategy:
            ----------------
            Perform tasks with larger (minimum - actual) first.

            Why?
            ----
            These tasks require a larger extra reserve of energy,
            so handling them earlier minimizes the required initial energy.
        */

        // Sort tasks in descending order of (minimum - actual)
        sort(tasks.begin(), tasks.end(),
            [&](vector<int> &a, vector<int> &b) {

                return (a[1] - a[0]) >
                       (b[1] - b[0]);
            });

        // Stores the minimum initial energy required
        long long ans = 0;

        // Current available energy while performing tasks
        long long energy = 0;

        // Process each task one by one
        for(int i = 0; i < tasks.size(); i++) {

            int actual = tasks[i][0];
            int minimum = tasks[i][1];

            /*
                Before starting the task,
                current energy must be at least 'minimum'
            */
            if(energy < minimum) {

                /*
                    Increase initial energy by the deficit amount
                */
                ans += (minimum - energy);

                // Update current energy to required minimum
                energy = minimum;
            }

            /*
                Perform the task

                Energy decreases by 'actual'
                after completing the task
            */
            energy -= actual;
        }

        // Final minimum initial energy required
        return (int)ans;
    }
};
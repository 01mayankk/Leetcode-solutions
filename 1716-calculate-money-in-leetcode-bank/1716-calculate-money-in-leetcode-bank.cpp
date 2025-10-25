class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
    int extra_days = n % 7;
    int total = 0;

    // Sum of full weeks
    for (int i = 0; i < weeks; i++) {
        int week_start = i + 1;            // Monday's amount for this week
        total += 7 * week_start + 21;      // sum of 7 consecutive days
        // Explanation: sum of 7 days = 7*week_start + (1+2+3+4+5+6) = 7*week_start + 21
    }

    // Sum of remaining days
    total += extra_days * (weeks + 1) + (extra_days * (extra_days - 1)) / 2;
    // Explanation: start from Monday of next week (weeks+1), add 0..extra_days-1

    return total;

    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int currentstreak = 1;
        int longeststreak = 1;
        int current;
        unordered_set<int>sequence(nums.begin(), nums.end());

        for(int num : sequence)
        {
            currentstreak = 0;
            if(sequence.find(num - 1) == sequence.end())
            {
                current = num;
                currentstreak += 1;

                while(sequence.find(current + 1) != sequence.end())
                {
                    current++;
                    currentstreak++;
                }

            }

            longeststreak = max(currentstreak, longeststreak);
        }

        return longeststreak;

        

    }
};
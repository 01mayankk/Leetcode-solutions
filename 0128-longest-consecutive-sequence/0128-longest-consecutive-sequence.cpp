class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int currentstreak ;
        int longeststreak = 0;
        int current;
        unordered_set<int>sequence(nums.begin(), nums.end());

        if(sequence.empty())
        {
            return {};
        }
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
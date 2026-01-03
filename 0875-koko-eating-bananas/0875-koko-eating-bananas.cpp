class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int minSpeed = 1;

        int maxSpeed = *max_element(piles.begin(), piles.end());

        while(minSpeed < maxSpeed)
        {
            int midSpeed = minSpeed + (maxSpeed - minSpeed) / 2;

            int hours = 0;

            for(int pile : piles)
            {
                hours += (pile + midSpeed - 1) / midSpeed;
            }

            if(hours <= h)
            {
                maxSpeed = midSpeed;
            }
            else
            {
                minSpeed = midSpeed + 1;
            }
        }  

        return minSpeed; 
    }
};
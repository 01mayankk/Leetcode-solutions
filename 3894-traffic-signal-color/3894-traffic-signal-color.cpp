class Solution {
public:
    string trafficSignal(int timer) {
        
        // If timer is exactly 0 → signal is Green
        if(timer == 0)
        {
            return "Green";
        }
        
        // If timer is exactly 30 → signal is Orange
        else if(timer == 30)
        {
            return "Orange";
        }
        
        // If timer is between 31 and 90 (inclusive) → signal is Red
        else if(timer > 30 && timer <= 90)
        {
            return "Red";
        }
        
        // For any other timer value → invalid input
        return "Invalid";
    }
};
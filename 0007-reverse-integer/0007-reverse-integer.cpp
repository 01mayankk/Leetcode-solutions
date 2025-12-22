class Solution {
public:
    int reverse(int x) {
    if (x == INT_MIN) {
        return 0; 
    }

    if (x < 0) {
        return -reverse(-x);
    }

    long long reversed = 0;
    while (x != 0) {
        int digit = x % 10;
        if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && digit > INT_MAX % 10)) {
            return 0; 
        }
        reversed = reversed * 10 + digit;
        x /= 10;
    }

    return (int)reversed;
} 

};
class Solution {
public:
    bool isHappy(int n) {
        
        unordered_set<int> seen;

        while (n != 1 && !seen.count(n)) {
            seen.insert(n);
            n = getNext(n);
        }
        
        return n == 1;
    }

private:
    int getNext(int number) {
        int sum = 0;
        while (number > 0) {
            int digit = number % 10; 
            sum += digit * digit; 
            number /= 10; 
        }
        return sum; 
    }
};

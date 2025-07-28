class Solution {
public:
    int hammingWeight(int n) {

        bitset<64>ones(n);

        return ones.count();
    }
};
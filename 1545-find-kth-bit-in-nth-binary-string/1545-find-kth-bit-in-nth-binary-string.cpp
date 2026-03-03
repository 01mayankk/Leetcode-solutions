class Solution {
public:
    char findKthBit(int n, int k) {
        
        // Base case:
        // S1 = "0"
        // So if n == 1, the only bit is '0'
        if (n == 1) return '0';
        
        // Length of Sn is (2^n - 1)
        // Because Sn = Sn-1 + "1" + reverse(invert(Sn-1))
        int length = (1 << n) - 1;
        
        // Middle position always contains '1'
        int mid = length / 2 + 1;
        
        // If k is exactly at middle position,
        // answer is always '1'
        if (k == mid) return '1';
        
        // If k lies in first half,
        // it is same as kth bit of Sn-1
        if (k < mid) 
            return findKthBit(n - 1, k);
        
        // If k lies in second half:
        // It corresponds to reverse(invert(Sn-1))
        // So we map position and invert the result
        return findKthBit(n - 1, length - k + 1) == '0' ? '1' : '0';
    }
};
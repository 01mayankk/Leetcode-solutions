class Fancy {
public:
    const long long MOD = 1e9 + 7;   // modulo value given in problem

    vector<long long> arr;   // stores normalized values of elements
    long long mul = 1;       // global multiplication factor
    long long add = 0;       // global addition factor


    // Function to compute (a^b) % MOD using Binary Exponentiation
    long long modPow(long long a, long long b) {
        long long res = 1;
        a %= MOD;

        while (b) {
            // If current bit of exponent is 1, multiply result
            if (b & 1) 
                res = (res * a) % MOD;

            // Square the base
            a = (a * a) % MOD;

            // Move to next bit
            b >>= 1;
        }

        return res;
    }


    // Function to compute modular inverse using Fermat's Little Theorem
    // x^(MOD-2) % MOD gives modular inverse when MOD is prime
    long long modInv(long long x) {
        return modPow(x, MOD - 2);
    }


    // Constructor
    Fancy() {
        // initially no elements
    }


    // Append a value to the sequence
    void append(int val) {

        /*
        Current transformation applied to elements is:
        actual_value = stored_value * mul + add

        To store the new value properly, we reverse this transformation.
        */

        // Remove the addition effect
        long long normalized = ((val - add) % MOD + MOD) % MOD;

        // Remove the multiplication effect using modular inverse
        normalized = (normalized * modInv(mul)) % MOD;

        // Store normalized value
        arr.push_back(normalized);
    }


    // Add 'inc' to every element in the sequence
    void addAll(int inc) {

        /*
        Instead of updating every element, we update
        the global addition factor.
        */

        add = (add + inc) % MOD;
    }


    // Multiply every element by m
    void multAll(int m) {

        /*
        If we multiply all elements:
        (value * mul + add) * m

        New transformation becomes:
        mul = mul * m
        add = add * m
        */

        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }


    // Return the element at index idx
    int getIndex(int idx) {

        // If index is out of bounds
        if (idx >= arr.size())
            return -1;

        /*
        Convert stored normalized value to actual value
        using current transformation
        */

        long long val = (arr[idx] * mul) % MOD;
        val = (val + add) % MOD;

        return val;
    }
};
/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
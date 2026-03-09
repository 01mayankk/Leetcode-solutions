class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {

        const long long MOD = 1e9 + 7;

        int maxN = zero + one;

        // factorial and inverse factorial for nCr
        vector<long long> fact(maxN + 1);
        vector<long long> invFact(maxN + 1);

        fact[0] = 1;

        // Precompute factorials
        for (int i = 1; i <= maxN; i++)
            fact[i] = (fact[i - 1] * i) % MOD;

        // Fast modular exponentiation
        auto power = [&](long long base, long long exp) {
            long long res = 1;
            base %= MOD;

            while (exp > 0) {
                if (exp & 1)
                    res = (res * base) % MOD;

                base = (base * base) % MOD;
                exp >>= 1;
            }
            return res;
        };

        // Compute inverse factorial using Fermat's theorem
        invFact[maxN] = power(fact[maxN], MOD - 2);

        for (int i = maxN - 1; i >= 0; i--)
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;

        // Combination function nCr
        auto C = [&](int n, int r) -> long long {
            if (r < 0 || r > n) return 0;
            return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
        };

        /*
        F(N,K,L)
        Number of ways to divide N items into K blocks
        where each block size <= L
        */
        auto F = [&](int N, int K, int L) -> long long {

            if (K <= 0 || K > N)
                return 0;

            long long ans = 0;

            // maximum inclusion-exclusion terms
            int maxJ = (N - K) / L;

            for (int j = 0; j <= maxJ; j++) {

                long long term =
                    C(K, j) * C(N - j * L - 1, K - 1) % MOD;

                // inclusion-exclusion sign
                if (j % 2)
                    ans = (ans - term + MOD) % MOD;
                else
                    ans = (ans + term) % MOD;
            }

            return ans;
        };

        /*
        maximum possible zero blocks
        because between zeros we need ones
        */
        int maxK = min(zero, one + 1);

        // Precompute one block possibilities
        vector<long long> fOne(maxK + 2);

        for (int k = 1; k <= maxK + 1; k++)
            fOne[k] = F(one, k, limit);

        long long ans = 0;

        // try all possible number of zero blocks
        for (int k = 1; k <= maxK; k++) {

            long long fz = F(zero, k, limit);

            if (fz == 0) continue;

            /*
            possible one block counts:

            k-1
            k
            k+1
            */

            long long fo =
                (fOne[k - 1] + 2 * fOne[k] + fOne[k + 1]) % MOD;

            ans = (ans + fz * fo) % MOD;
        }

        return (int)ans;
    }
};
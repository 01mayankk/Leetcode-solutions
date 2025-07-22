class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> trusts(n + 1, 0);     // index 1 to n
    vector<int> trustedBy(n + 1, 0);

    for (auto& t : trust) {
        int a = t[0], b = t[1];
        trusts[a]++;         // a trusts someone
        trustedBy[b]++;      // b is trusted by someone
    }

    for (int i = 1; i <= n; ++i) {
        if (trusts[i] == 0 && trustedBy[i] == n - 1)
            return i; // This person is the judge
    }

    return -1; // No judge found
}

};
class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1000000007;
        long long freq[26] = {0};
        long long ans = 0;

        for (int i = 0; i < s.length(); i++) {
            long long preans = (ans + 1) % MOD;
            preans = (preans - freq[s[i] - 'a'] + MOD) % MOD;

            ans = (ans + preans) % MOD;
            freq[s[i] - 'a'] = (freq[s[i] - 'a'] + preans) % MOD;
        }

        return ans;
    }
};
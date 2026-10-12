class Solution {
    static const long long MOD = 1000000007;

    long long power(long long a, long long b) {
        long long res = 1;

        while (b) {
            if (b & 1)
                res = (res * a) % MOD;

            a = (a * a) % MOD;
            b >>= 1;
        }

        return res;
    }

public:
    int findMaxProduct(vector<int>& arr) {

        int negCount = 0;
        int zeroCount = 0;
        int maxNegative = INT_MIN;

        long long product = 1;

        for (int x : arr) {

            if (x == 0) {
                zeroCount++;
                continue;
            }

            if (x < 0) {
                negCount++;
                maxNegative = max(maxNegative, x);
            }

            long long val = (x % MOD + MOD) % MOD;
            product = (product * val) % MOD;
        }

        int n = arr.size();

        if (zeroCount == n)
            return 0;

        if (negCount == 1 && negCount + zeroCount == n) {
            if (zeroCount > 0)
                return 0;
            return maxNegative;
        }

        if (negCount % 2 == 1) {

            long long rem = (maxNegative % MOD + MOD) % MOD;

            product = (product * power(rem, MOD - 2)) % MOD;
        }

        return (int)product;
    }
};

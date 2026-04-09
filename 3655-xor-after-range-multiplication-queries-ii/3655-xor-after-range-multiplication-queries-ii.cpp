#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        int B = sqrt(n);

        vector<vector<vector<array<int, 3>>>> store(
            B + 1, vector<vector<array<int, 3>>>(B + 1)
        );

        for (int i = 0; i < m; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            int v = queries[i][3];

            if (k >= B) {
                for (int idx = l; idx <= r; idx += k) {
                    nums[idx] = (1LL * nums[idx] * v) % MOD;
                }
            } else {
                int remainder = l % k;
                store[k][remainder].push_back({l, r, v});
            }
        }

        for (int k = 1; k < B; k++) {
            for (int rem = 0; rem < k; rem++) {
                if (store[k][rem].empty()) continue;

                auto& queriesList = store[k][rem];
                int chainLength = (n - rem + k - 1) / k;

                vector<long long> diff(chainLength + 1, 1);

                for (auto& q : queriesList) {
                    int l = q[0];
                    int r = q[1];
                    int v = q[2];

                    int startPos = (l - rem) / k;
                    int endPos = (r - rem) / k;

                    if (startPos < 0) startPos = 0;
                    if (endPos >= chainLength) endPos = chainLength - 1;
                    if (startPos > endPos) continue;

                    diff[startPos] = (diff[startPos] * v) % MOD;

                    if (endPos + 1 < chainLength) {
                        diff[endPos + 1] =
                            (diff[endPos + 1] * modInverse(v)) % MOD;
                    }
                }

                long long curr = 1;
                for (int pos = 0; pos < chainLength; pos++) {
                    curr = (curr * diff[pos]) % MOD;
                    int idx = rem + pos * k;
                    nums[idx] = (1LL * nums[idx] * curr) % MOD;
                }
            }
        }

        int res = 0;
        for (int num : nums) {
            res ^= num;
        }
        return res;
    }

private:
    long long modInverse(long long a) {
        return power(a, MOD - 2);
    }

    long long power(long long a, long long b) {
        long long result = 1;
        a %= MOD;
        while (b > 0) {
            if (b & 1) result = (result * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return result;
    }
};
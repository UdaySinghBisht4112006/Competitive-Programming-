class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        long long ans = LLONG_MAX;

        multiset<long long> small, large;
        long long sumSmall = 0;

        auto add = [&](long long x) {
            if ((int)small.size() < k - 1) {
                small.insert(x);
                sumSmall += x;
            } else if (!small.empty() && x < *prev(small.end())) {
                auto it = prev(small.end());
                sumSmall -= *it;
                large.insert(*it);
                small.erase(it);

                small.insert(x);
                sumSmall += x;
            } else {
                large.insert(x);
            }
        };

        auto remove = [&](long long x) {
            auto it = small.find(x);
            if (it != small.end()) {
                sumSmall -= x;
                small.erase(it);

                if (!large.empty()) {
                    auto it2 = large.begin();
                    small.insert(*it2);
                    sumSmall += *it2;
                    large.erase(it2);
                }
            } else {
                it = large.find(x);
                if (it != large.end()) large.erase(it);
            }
        };

        int r = 1;
        for (int l = 1; l < n; l++) {
            while (r < n && r <= l + dist) {
                add(nums[r]);
                r++;
            }

            if ((int)small.size() == k - 1) {
                ans = min(ans, nums[0] + sumSmall);
            }

            remove(nums[l]);
        }

        return ans;
    }
};

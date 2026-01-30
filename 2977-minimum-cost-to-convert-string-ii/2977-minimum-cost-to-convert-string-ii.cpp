class Solution {
public:
    static constexpr long long INF = 1e18;

    struct Trie {
        int id = -1;
        unordered_map<char, Trie*> next;
    };

    void insert(Trie* root, const string& s, int id) {
        Trie* cur = root;
        for (char c : s) {
            if (!cur->next[c]) cur->next[c] = new Trie();
            cur = cur->next[c];
        }
        cur->id = id;
    }

    long long minimumCost(string source, string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {
        int n = source.size();
        unordered_map<string,int> mp;
        int idx = 0;

        for (int i = 0; i < original.size(); i++) {
            if (!mp.count(original[i])) mp[original[i]] = idx++;
            if (!mp.count(changed[i])) mp[changed[i]] = idx++;
        }

        int k = idx;
        vector<vector<long long>> dist(k, vector<long long>(k, INF));
        for (int i = 0; i < k; i++) dist[i][i] = 0;

        for (int i = 0; i < original.size(); i++) {
            int u = mp[original[i]];
            int v = mp[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for (int mid = 0; mid < k; mid++) {
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < k; j++) {
                    if (dist[i][mid] < INF && dist[mid][j] < INF) {
                        dist[i][j] = min(dist[i][j],
                                         dist[i][mid] + dist[mid][j]);
                    }
                }
            }
        }

        Trie* root = new Trie();
        for (auto &p : mp) {
            insert(root, p.first, p.second);
        }

        vector<long long> dp(n + 1, INF);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (source[i] == target[i]) {
                dp[i] = dp[i + 1];
            }

            Trie* cur = root;
            for (int j = i; j < n; j++) {
                if (!cur->next.count(source[j])) break;
                cur = cur->next[source[j]];
                if (cur->id == -1) continue;

                int len = j - i + 1;
                if (i + len > n) continue;

                string tsub = target.substr(i, len);
                if (!mp.count(tsub)) continue;

                int u = cur->id;
                int v = mp[tsub];

                if (dist[u][v] < INF && dp[i + len] < INF) {
                    dp[i] = min(dp[i],
                                dist[u][v] + dp[i + len]);
                }
            }
        }

        return dp[0] == INF ? -1 : dp[0];
    }
};

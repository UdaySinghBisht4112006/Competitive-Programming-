class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        if (n < k || n - k + 1 < (1 << k)) return false;
        
        vector<bool> seen(1 << k, false);
        int hash = 0, count = 0;
        
        for (int i = 0; i < n; i++) {
            hash = ((hash << 1) & ((1 << k) - 1)) | (s[i] - '0');
            
            if (i >= k - 1) {
                if (!seen[hash]) {
                    seen[hash] = true;
                    count++;
                    if (count == (1 << k)) return true;
                }
            }
        }
        
        return false;
    }
};
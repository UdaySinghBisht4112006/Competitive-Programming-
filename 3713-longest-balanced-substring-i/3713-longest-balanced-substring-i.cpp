class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 1;
        
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                
                int count = 0;
                bool valid = true;
                
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        if (count == 0) 
                            count = freq[k];
                        else if (freq[k] != count) {
                            valid = false;
                            break;
                        }
                    }
                }
                
                if (valid)
                    ans = max(ans, j - i + 1);
            }
        }
        
        return ans;
    }
};

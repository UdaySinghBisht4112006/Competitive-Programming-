class Solution {
public:
    int minOperations(string s) {
        int a = 0, b = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] != (i % 2 ? '1' : '0')) a++;
            if(s[i] != (i % 2 ? '0' : '1')) b++;
        }

        return min(a, b);
    }
};
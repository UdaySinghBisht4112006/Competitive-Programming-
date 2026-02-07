class Solution {
public:
    int minimumDeletions(string s) {
        int removeCount = 0;
        int bCount = 0;

        for (char ch : s) {
            if (ch == 'b') {
                bCount++;
            } else {
                removeCount = min(removeCount + 1, bCount);
            }
        }
        return removeCount;
    }
};

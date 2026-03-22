class Solution {
public:
    void r(vector<vector<int>>& m) {
        int n = m.size();
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(m[i][j], m[j][i]);
            }
        }
        for(int i = 0; i < n; i++) {
            reverse(m[i].begin(), m[i].end());
        }
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i = 0; i < 4; i++) {
            if(mat == target) return true;
            r(mat);
        }
        return false;
    }
};
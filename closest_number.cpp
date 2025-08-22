class Solution {
  public:
    int closestNumber(int n, int m) {
        if (m < 0) {
            m = -m;
        }
        int rem = n % m;
        if (rem < 0) {
            rem += m;
        }
        if (rem == 0) {
            return n;
        }

        int a = n - rem;
        int b = n + (m - rem);

        int da = abs(n - a);
        int db = abs(n - b);

        if (da == db) {
            if (abs(a) > abs(b)) {
                return a;
            } 
            else {
                return b;
            }
        }

        if (da < db) {
            return a;
        } 
        else {
            return b;
        }
    }
};

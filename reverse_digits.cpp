class Solution {
  public:
    int reverseDigits(int n) {
        int num=0;
        int rem;
        while(n!=0)
        {
            rem=n%10;
            num=(num*10)+rem;
            n=n/10;
        }
        return num;
    }
};
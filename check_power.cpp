class Solution {
  public:
    int isPowerOfAnother(int X, int Y) {
       if(X==1)
       {
           return Y==1;
       }
       if (Y<1)
       {
           return 0;
       }
       while(Y%X==0)
       {
           Y=Y/X;
       }
       return Y==1;
    }
};
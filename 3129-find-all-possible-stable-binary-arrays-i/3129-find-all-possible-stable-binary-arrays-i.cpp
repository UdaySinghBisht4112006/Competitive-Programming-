class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1000000007;

        static long long dp[201][201][2][201];
        memset(dp,0,sizeof(dp));

        if(zero>0) dp[1][0][0][1]=1;
        if(one>0) dp[0][1][1][1]=1;

        for(int z=0;z<=zero;z++){
            for(int o=0;o<=one;o++){
                for(int last=0;last<2;last++){
                    for(int run=1;run<=limit;run++){

                        long long cur=dp[z][o][last][run];
                        if(cur==0) continue;

                        if(last==0){
                            if(z+1<=zero && run+1<=limit)
                                dp[z+1][o][0][run+1]=(dp[z+1][o][0][run+1]+cur)%MOD;

                            if(o+1<=one)
                                dp[z][o+1][1][1]=(dp[z][o+1][1][1]+cur)%MOD;
                        }
                        else{
                            if(o+1<=one && run+1<=limit)
                                dp[z][o+1][1][run+1]=(dp[z][o+1][1][run+1]+cur)%MOD;

                            if(z+1<=zero)
                                dp[z+1][o][0][1]=(dp[z+1][o][0][1]+cur)%MOD;
                        }
                    }
                }
            }
        }

        long long ans=0;

        for(int r=1;r<=limit;r++){
            ans=(ans+dp[zero][one][0][r])%MOD;
            ans=(ans+dp[zero][one][1][r])%MOD;
        }

        return ans;
    }
};
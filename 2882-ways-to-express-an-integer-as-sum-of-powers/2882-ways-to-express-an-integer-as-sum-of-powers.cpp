class Solution {
public:
    long long mod= 1e9+7;
    int dp(long long sum,long long i,int n,int x,vector<vector<long long>> &memo){
        if(sum == n) return 1;
        if(sum > n || i>n) return 0;
        if (memo[sum][i]!=-1) return memo[sum][i];
        memo[sum][i]=(((long long) dp(sum+(long long)pow(i,x),i+1,n,x,memo)%mod) + ((long long)dp(sum,i+1,n,x,memo)%mod))%mod;
        return memo[sum][i];
    }
    int numberOfWays(int n, int x) {
        vector<vector<long long>> memo(n+1,vector<long long> (n+1,-1));
        dp(0,1,n,x,memo);
        return memo[0][1];
    }
};
class Solution {
public:
    bool f(int i,int k,vector<int>& st,vector<vector<long long>> &dp){
        int n=st.size();
        if(i==n-1) return 1;
        if(dp[i][k]!=-1) return dp[i][k];
        for(int ind=i+1;ind<n;ind++){
            if(st[ind]-st[i]==k-1){
                if(f(ind,k-1,st,dp)) return dp[i][k]=1;
            }
            if(st[ind]-st[i]==k){
                if(f(ind,k,st,dp)) return dp[i][k]=1;
            }
            if(st[ind]-st[i]==k+1){
                if(f(ind,k+1,st,dp)) return dp[i][k]=1;
            }
        }
        return dp[i][k]=0;

    }
    bool canCross(vector<int>& st) {
        vector<vector<long long>> dp(st.size(),vector<long long>(st.size(),-1));
        return f(0,0,st,dp);
    }
};
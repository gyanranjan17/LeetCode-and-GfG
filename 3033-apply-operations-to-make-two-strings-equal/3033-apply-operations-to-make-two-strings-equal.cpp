class Solution {
public:
    int f(int i,int j,vector<int>&v,vector<vector<int>> &dp,int x){
        if(i>=v.size() || j<0 || j<=i) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int a=0,b=0,c=0;
        a=v[i+1]-v[i]+f(i+2,j,v,dp,x);
        b=v[j]-v[j-1]+f(i,j-2,v,dp,x);
        c=x+f(i+1,j-1,v,dp,x);
        return dp[i][j]=min({a,b,c});
    }
    int minOperations(string s1, string s2, int x) {
        vector<vector<int>> dp(501,vector<int>(501,-1));
        vector<int> v;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                v.push_back(i);
            }
        }
        if(v.size()%2) return -1;
        return f(0,v.size()-1,v,dp,x);
    }
};
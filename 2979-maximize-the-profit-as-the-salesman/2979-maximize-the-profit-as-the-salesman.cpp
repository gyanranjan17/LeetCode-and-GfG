class Solution {
public:
    int f(int i, int n,  map<int,vector<pair<int,int>>>&m, vector<int>&dp){
        if(i==n)return 0;

        int t=0,nt=0;
        if(dp[i]!=-1)return dp[i];
        if(m.find(i)!=m.end()){
            auto x=m[i];
            for(auto j : x){
                t=max(t,j.second+f(j.first+1,n,m,dp));
            }
        }
        nt=f(i+1,n,m,dp);

        return dp[i]=max(t,nt);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& v){
        map<int,vector<pair<int,int>>>m;

        for(auto i : v){
            m[i[0]].push_back({i[1],i[2]});
        }
        vector<int>dp(n+1,-1);
        return f(0,n,m,dp);
    }
};
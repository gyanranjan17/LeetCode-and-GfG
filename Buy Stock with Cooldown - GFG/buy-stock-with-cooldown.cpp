//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
        long long f(int i,int buy,vector<long long>& prices,vector<vector<long long>> &dp){
        if(i>=prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            int b=-prices[i] + f(i+1,0,prices,dp);
            int nb= f(i+1,1,prices,dp);
            return dp[i][buy]=max(b,nb);
        }
        else{
            int s=prices[i]+f(i+2,1,prices,dp);
            int ns=f(i+1,0,prices,dp);
            return dp[i][buy]=max(s,ns);
        }
    }
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        vector<vector<long long>> dp(n,vector<long long>(2,-1));
        return f(0,1,prices,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
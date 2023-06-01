//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int mod=1e9+7;
    //Function to count number of ways to reach the nth stair.
    int f(int i,vector<int> &dp){
        if(i==0) return 1;
        if(i==1) return 1;
        if(dp[i]!=-1) return dp[i];
        int one=f(i-1,dp);
        int two=f(i-2,dp);
        
        return dp[i]=(one+two)%mod;
    }
    int countWays(int n)
    {
        // your code here
        vector<int> dp(n+1,-1);
        return f(n,dp);
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends
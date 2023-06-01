//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int mod=1e9+7;
    //Function to count number of ways to reach the nth stair.
    
    int countWays(int n)
    {
        // your code here
        vector<int> dp(n+1,-1);
        for(int i=0;i<=n;i++){
            if(i==0 || i==1) dp[i]=1;
            else {
                int one=dp[i-1];
                int two=dp[i-2];
                dp[i]=(one+two)%mod;
            }
        }
        return dp[n];
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
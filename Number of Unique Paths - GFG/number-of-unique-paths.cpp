//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
     int f(int m,int n,vector<vector<int>> &dp){
        if(m==0 && n==0) return dp[m][n]=1;
        if(m<0 || n<0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        int u=f(m-1,n,dp);
        int l=f(m,n-1,dp);
        return dp[m][n]=l+u;
    }
    
    int NumberOfPath(int a, int b)
    {
        //code here
        vector<vector<int>> dp(a,vector<int>(b,-1));
        return f(a-1,b-1,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends
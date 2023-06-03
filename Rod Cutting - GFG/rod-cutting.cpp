//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int f(int i,int N,int price[],vector<vector<int>>&dp){
        if(i==0) return N*price[0];
        if(dp[i][N]!=-1) return dp[i][N];
        int nt=f(i-1,N,price,dp);
        int t=INT_MIN;
        int rodlength=i+1;
        if(rodlength<=N) t=price[i]+f(i,N-rodlength,price,dp);
        return dp[i][N]=max(t,nt);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(n-1,n,price,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
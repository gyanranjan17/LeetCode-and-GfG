//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int f(int i,int tran,int prices[],vector<vector<int>> &dp,int k,int N){
        if(i==N || tran==2*k) return 0;
        if(dp[i][tran]!=-1) return dp[i][tran];
        if(tran%2==0){
            int b=-prices[i] + f(i+1,tran+1,prices,dp,k,N);
            int nb= f(i+1,tran,prices,dp,k,N);
            return dp[i][tran]=max(b,nb);
        }
        else{
            int s=prices[i]+f(i+1,tran+1,prices,dp,k,N);
            int ns=f(i+1,tran,prices,dp,k,N);
            return dp[i][tran]=max(s,ns);
        }
    }
    int maxProfit(int k, int N, int A[]) {
        // code here
        vector<vector<int>> dp(N,vector<int>(2*k,-1));
        return f(0,0,A,dp,k,N);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends
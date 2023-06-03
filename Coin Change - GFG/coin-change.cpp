//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long f(int i,int a,int coins[],vector<vector<long long>> &dp){
        if(i==0){
            if(a%coins[i]==0) return 1;
            else return 0;
        }
        if(dp[i][a]!=-1) return dp[i][a];
        long long np=f(i-1,a,coins,dp);
        long long p=0;
        if(coins[i]<=a)
        p=f(i,a-coins[i],coins,dp);
        return dp[i][a]=p+np;
    }
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long>> dp(N,vector<long long>(sum+1,-1));
        return f(N-1,sum,coins,dp); 
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends
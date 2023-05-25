//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
 long long int mod = 1e9 + 7;
  long long int rec(long long int n,vector<long long int> &memo){
      if(memo[n]==-1){
            
            int res;
            if(n==0 || n==1) memo[n]= n;
            else
           memo[n]=(rec(n-1,memo) + rec(n-2,memo))%mod;
        }
        return memo[n];
  }
 
  
    long long int nthFibonacci(long long int n){
        // code here
        vector<long long int> memo(n+1,-1);
        return rec(n,memo);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
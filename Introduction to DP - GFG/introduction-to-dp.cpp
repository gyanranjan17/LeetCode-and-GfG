//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long mod=1e9+7;
    long long int f(vector<long long int> &v, int n){
        if(v[n]!=-1) return v[n];
        if(n==0 || n==1) return v[n]=n;
        return v[n]= (f(v,n-1)+ f(v,n-2))%mod;
    }
    long long int topDown(int n) {
        // code here
        vector<long long int> v(n+1,-1);
        return f(v,n)%mod;
    }
    long long int bottomUp(int n) {
        // code here
        int prev2=0,prev=1;
        for(int i=2;i<=n;i++){
            int cur=(prev2+prev)%mod;
            prev2=prev;
            prev=cur;
        }
        return prev;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends
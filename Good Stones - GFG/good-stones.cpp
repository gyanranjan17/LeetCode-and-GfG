//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    bool solve(int ind, vector<int> &arr, vector<int> &dp, int n) {
        if(ind < 0 or ind >= n) return true;
        if(dp[ind] != -1) return dp[ind];
        dp[ind] = 0;
        return dp[ind] = solve(ind + arr[ind], arr, dp, n);
    }
    int goodStones(int n,vector<int> &arr){
        vector<int> dp(n+1, -1);
        for(int i=0;i<n;i++) {
            if(dp[i] == -1) solve(i, arr, dp, n);
        }
        
        int count = 0;
        for(int i=0;i<n;i++) {
            if(dp[i]) count++;
        }
        
        return count;
    }  
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends
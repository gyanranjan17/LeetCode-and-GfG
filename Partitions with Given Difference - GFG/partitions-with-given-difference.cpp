//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod=1e9+7;
	int f(vector<int>& arr, int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0){
                    if(arr[i]==0 && j==0) dp[i][j]= 2;
                    else if(j==0 || arr[0]==j) dp[i][j]= 1;
                    else dp[i][j]= 0;
                }
                else{
                    int np=dp[i-1][j]%mod;
                    int p=0;
                    if(arr[i]<=j)
                    p=dp[i-1][j-arr[i]]%mod;
                    dp[i][j]=(np+p)%mod;
                }
            }
        }
        return dp[n-1][sum];
        
	}
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int s=0;
        for(int i=0;i<n;i++)
        s+=arr[i];
        if(s-d>=0 && (s-d)%2==0)
        return f(arr,n,(s-d)/2);
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends
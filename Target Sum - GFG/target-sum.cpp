//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
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
                    int np=dp[i-1][j];
                    int p=0;
                    if(arr[i]<=j)
                    p=dp[i-1][j-arr[i]];
                    dp[i][j]=(np+p);
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
    int findTargetSumWays(vector<int>&nums ,int target) {
        //Your code here
        return countPartitions(nums.size(),target,nums);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
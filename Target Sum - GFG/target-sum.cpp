//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int f(int i,int t,vector<int>& nums,vector<vector<int>> &dp){
        if(i==0){
            if(nums[i]==0 && t==0) return 2;
            if(t==0 || nums[0]==t) return 1;
            return 0;
        }
        if(dp[i][t]!=-1)return dp[i][t];
        int np=f(i-1,t,nums,dp);
        int p=0;
        if(nums[i]<=t)
        p=f(i-1,t-nums[i],nums,dp);
        return dp[i][t]=p+np;

    }
    int findTargetSumWays(vector<int>&nums ,int target) {
        //Your code here
        int n=nums.size(),s=0;
        // vector<vector<int>> dp(n,vector<int>((s-target)/2+1,-1));
        
        for(int i=0;i<n;i++){
            s+=nums[i];
        }
        if(s-target>=0 && (s-target)%2==0){
        vector<vector<int>> dp(n,vector<int>((s-target)/2+1,-1));
        return f(n-1,(s-target)/2,nums,dp);
        }
        return 0;
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
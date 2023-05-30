//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool f(int i,int sum,vector<int>&arr,vector<vector<int>> &dp){
        if(i<0 ) {
            if(sum==0) return 1;
            return 0;
        }
        
        
        if(dp[i][sum]!=-1) return dp[i][sum];
        int nt=f(i-1,sum,arr,dp);
        int t=0;
        if(sum>=arr[i])
        t=f(i-1,sum-arr[i],arr,dp);
        return dp[i][sum]=(nt | t);
        
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return f(n-1,sum,arr,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
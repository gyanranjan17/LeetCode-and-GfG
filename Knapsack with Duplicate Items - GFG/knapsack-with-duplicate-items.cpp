//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // int f(int i,int W,int val[],int wt[],vector<vector<int>> &dp){
    //     if(i==0){
    //         if(wt[0]<=W) return (W/wt[0])*val[0];
    //         else return 0;
    //     } 
    //     if(dp[i][W]!=-1) return dp[i][W];
    //     int np=f(i-1,W,val,wt,dp);
    //     int p=INT_MIN;
    //     if(wt[i]<=W)
    //     p=val[i]+f(i,W-wt[i],val,wt,dp);
    //     return dp[i][W]=max(np,p);
    // }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<int> prev(W+1);
        for(int i=0;i<N;i++){
            for(int j=0;j<W+1;j++){
                if(i==0){
                    if(wt[0]<=j) prev[j]= (j/wt[0])*val[0];
                    else prev[j]= 0;
                } 
                else{
                    int np=prev[j];
                    int p=INT_MIN;
                    if(wt[i]<=j)
                    p=val[i]+prev[j-wt[i]];
                    prev[j]=max(np,p);
                }
            }
        }
        return prev[W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
  
    
    int minCostClimbingStairs(vector<int>&cost ,int n) {
        //Write your code here
        
        int prev2=0,prev=0;
        for(int i=2;i<=n;i++){
            int f=prev + cost[i-1];
            int s=prev2 + cost[i-2];
            int cur=min(f,s);
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
        int N;
        
        cin>>N;
        vector<int>cost(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>cost[i];
        }

        Solution ob;
        cout<<ob.minCostClimbingStairs(cost,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool isFeasible(int weights[],int days,int min,int N){
        int groups=1,csum=0;
        for(int i=0;i<N;i++){
            if(weights[i]>min)
                return false;

            if(csum+weights[i]>min){
                groups++;
                csum=weights[i];
                if(groups>days)
                return false;
            }
            else
            csum+=weights[i];
        }
        return true;
        
    }
    int leastWeightCapacity(int weights[], int N, int D) {
        // code here
        int sum=0,x=INT_MIN;
        for(int i=0;i<N;i++){
            sum+=weights[i];
            x=max(x,weights[i]);
        }
        int s=x,e=sum,res=INT_MAX;
        while(s<=e){
            int m=(s+e)/2;
            if(isFeasible(weights,D,m,N))
            {
                res=m;
                e=m-1;
            }
            else
            s=m+1;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends
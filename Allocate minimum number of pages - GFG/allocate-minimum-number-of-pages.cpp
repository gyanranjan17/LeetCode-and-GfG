//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isFeasible(int A[],int N,int M,int m){
         long long csum=0,students=1;
        for(int i=0;i<N;i++){
           
            if(A[i]>m)
            return 0;
            if(csum+A[i]>m){
                students++;
                csum=A[i];
                if(students>M)
                return 0;
            }
            else
            csum+=A[i];
        }
        return 1;
    }
    int findPages(int A[], int N, int M) 
    {
        int sum=0,mx=INT_MIN;
        if(N<M)
        return -1;
        
        for(int i=0;i<N;i++){
            sum+=A[i];
            mx=max(mx,A[i]);
            
        }
        long long s=mx,e=sum;
        int res=INT_MAX;
        while(s<=e){
            long long m=(s+e)/2;
            if(isFeasible(A,N,M,m)){
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
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends
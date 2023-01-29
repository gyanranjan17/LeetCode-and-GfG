//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int k) 
    { 
        // Complete the function
        unordered_map<int,int> m;
        int psum=0,res=0;
        for(int i=0;i<N;i++){
            psum+=A[i];
            if(psum==k) res=i+1;
            if(m.find(psum)==m.end())
            m.insert({psum,i});
            if(m.find(psum-k)!=m.end())
            res=max(res,i-m[psum-k]);
        }
        return res;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
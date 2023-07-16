//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int overlap(vector<pair<int,int>>in, int n){
        //Write your code here
        vector<pair<int,char>> v;
        for(auto x:in){
            v.push_back({x.first,'l'});
            v.push_back({x.second,'r'});
        }
        sort(v.begin(),v.end());
        int ans=0,c=0;
        for(auto x:v){
            if(x.second=='l') c++;
            else c--;
            ans=max(ans,c);
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<pair<int,int>>intervals;
	    for(int i = 0; i < n; i++){
	        int a, b;
	        cin >> a >> b;
	        intervals.push_back({a, b});
	    }
	    Solution ob;
	    int ans = ob.overlap(intervals, n);
	    cout << ans <<endl;
	}
	return 0;
}

// } Driver Code Ends
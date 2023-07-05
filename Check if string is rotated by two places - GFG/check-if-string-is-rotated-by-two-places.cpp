//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string a, string b)
    {
        // Your code here
        if(a.size()==1) return a==b;
        string x=a;
        reverse(a.begin(),a.begin()+2);
        reverse(a.begin()+2,a.end());
        reverse(a.begin(),a.end());
  
        
        reverse(x.begin(),x.end());
        reverse(x.begin(),x.begin()+2);
        reverse(x.begin()+2,x.end());
        return ((a==b) | (x==b));
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends
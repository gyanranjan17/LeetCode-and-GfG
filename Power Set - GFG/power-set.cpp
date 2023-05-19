//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    void subseq(int i,vector<string>&ans,string st,string s){
	        if(i==s.length()){
	            if(st!="")
	            ans.push_back(st);
	        return;
	        }
	        subseq(i+1,ans,st,s);
	        subseq(i+1,ans,st+s[i],s);
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans;
		    subseq(0,ans,"",s);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends
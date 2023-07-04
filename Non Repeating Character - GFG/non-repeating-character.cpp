//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string s)
    {
       //Your code here
       vector<int> v(26,-1);
        int res=1e9;
        for(int i=s.length()-1;i>=0;i--){
            if(v[s[i]-'a']==-1){
                v[s[i]-'a']=i;
            }
            else v[s[i]-'a']=-2;
        }
        for(int i=0;i<26;i++) {
            if(v[i]>=0){
                res=min(res,v[i]);
            }
        }
        if(res==1e9) return '$';
        return s[res];
       
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends
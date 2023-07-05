//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here 
        int i=0;
        string ans="";
        for(int j=0;j<s.size();j++){
            if(s[j]=='.'){
                if(j!=i){
                    ans=s.substr(i,j-i) + '.' + ans; 
                }
                i=j+1;
            }
            if(j==s.size()-1 && s[j]!='.'){
                ans=s.substr(i,j-i+1) + "." + ans;
            }
        }
        return ans.substr(0,ans.size()-1);
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        map<char,int>m;
        
        m['b']=0,m['a']=0,m['l']=0,m['o']=0,m['n']=0;
        
        for(auto i :s){
            m[i]++;
        }
        if(m['b']<1 || m['a']<1 || m['l']<2 || m['o']<2 || m['n']<1)return 0;
        
        vector<int>trav={m['b'],m['a'],m['n'],(m['l']/2),(m['o']/2)};
        int ans=INT_MAX;
        
        for(auto i :trav){
            ans=min(ans,i);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
   
    int maxInstance(string s){
        map<char,int> m;
        for(auto x:s){
            if(x=='a' || x=='b'|| x=='l' || x=='o' || x=='n')
            m[x]++;
        }
        if(m.size()<5)return 0;
        m['l']/=2;
        m['o']/=2;
        
        int ans=INT_MAX;
        for(auto i:m){
            ans=min(ans,i.second);
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
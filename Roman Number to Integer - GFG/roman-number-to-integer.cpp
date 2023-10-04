//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        unordered_map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        
        int num=0;
        for(int i=0;i<str.length();i++)
        {
            // if its last index
            if(i==str.length()-1)
            {
                num+=(mp[str[i]]);
                continue;
            }
            
            if(mp[str[i]]<mp[str[i+1]])
            num+=(-mp[str[i]]);
            else
            num+=mp[str[i]];
        }
        
        return num;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends
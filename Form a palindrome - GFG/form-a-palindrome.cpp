//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  int f(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        for(int i=0;i<text1.size()+1;i++){
            for(int j=0;j<text2.size()+1;j++){
                if(i==0 || j==0) dp[i][j]= 0;
                else{
                    if(text1[i-1]==text2[j-1]) dp[i][j]= 1+dp[i-1][j-1];
                    else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }       
        }
        return dp[text1.size()][text2.size()];
    }
    int countMin(string str){
    //complete the function here
        string rs=string(str.rbegin(),str.rend());
        return str.size()-f(str,rs);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
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

    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        return m+n-f(X,Y);
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends
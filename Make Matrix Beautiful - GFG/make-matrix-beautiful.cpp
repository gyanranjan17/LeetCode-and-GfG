//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > mat, int N)
    {
        // code here 
        vector<int> row(N),col(N);
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                col[j]+=mat[i][j];
                row[i]+=mat[i][j];
            }
        }
        int ans=0;
        int x=max(*max_element(row.begin(),row.end()),*max_element(col.begin(),col.end()));
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(row[i]>=col[j]){
                    col[j]+=(x-row[i]);
                    ans+=(x-row[i]);
                    row[i]=x;
                }
                else{
                    row[i]+=(x-col[j]);
                    ans+=(x-col[j]);
                    col[j]=x;
                }
            }
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
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends
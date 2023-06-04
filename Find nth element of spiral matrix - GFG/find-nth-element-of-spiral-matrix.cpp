//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int findK(int [MAX][MAX],int ,int ,int );
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        cout<<findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends


/*You are required to complete this method*/
int findK(int a[MAX][MAX], int m, int n, int k)
{
//Your code here
int top=0,bottom=m-1,right=n-1,left=0;
        int ans=0;
        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){
            ans++;
            if(ans==k) return a[top][i];
            }
            top++;
            for(int i=top;i<=bottom;i++){
            ans++;
            if(ans==k) return a[i][right];
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                ans++;
                if(ans==k) return a[bottom][i];
                }
                bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                ans++;
                if(ans==k) return a[i][left];
                }
                left++;
            }
        }
        return ans;
}


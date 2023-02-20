//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int n, int m, int x, int y){    
        vector<vector<int>>v(n,vector<int>(m,0));

        x--;

        y--;

        v[x][y]=0;

        

        queue<pair<int,int>>q;

        q.push({x,y});

        int count=0;

        while(!q.empty()){

            int k=q.size();

            count++;

            for(int i=0;i<k;i++){

                auto p=q.front();

                q.pop();

                int x=p.first;

                int y=p.second;

                

                if(x+1<n && v[x+1][y]==0 ){

                    v[x+1][y]=1;

                    q.push({x+1,y});

                }

                if(x-1>=0 && v[x-1][y]==0 ){

                    v[x-1][y]=1;

                    q.push({x-1,y});

                }

                if(y+1<m && v[x][y+1]==0 ){

                    v[x][y+1]=1;

                    q.push({x,y+1});

                }

                if(y-1>=0 && v[x][y-1]==0 ){

                    v[x][y-1]=1;

                    q.push({x,y-1});

                }

            }

        }

        return count-1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
	public:
    int timer=1;
    void dfs(int node,vector<int>&pis,vector<int>&disc,vector<int>&low,stack<int>&st,vector<vector<int>>&ans,vector<int>adj[]){
        st.push(node);
        pis[node]=1;
        low[node]=disc[node]=timer++;
        for(int x:adj[node]){
            if(pis[x])
            low[node]=min(low[node],disc[x]);
            else if(!disc[x]) {
                dfs(x,pis,disc,low,st,ans,adj);
                low[node]=min(low[node],low[x]);
            }
        }
        if(disc[node]==low[node]){
             vector<int> temp;
            while(st.top()!=node){
                temp.push_back(st.top());
                pis[st.top()]=0;
                st.pop();
            }
            temp.push_back(st.top());
            pis[st.top()]=0;
            st.pop();
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
            
        }
    }
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        //code here
        vector<int> pis(V,0),disc(V,0),low(V,0);
        stack<int> st;
        vector<vector<int>> ans;
        for(int i=0;i<V;i++){
            if(!disc[i])
            dfs(i,pis,disc,low,st,ans,adj);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}


// } Driver Code Ends
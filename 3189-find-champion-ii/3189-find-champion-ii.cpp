class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edge) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);
        for(int i=0;i<edge.size();i++){
            adj[edge[i][0]].push_back(edge[i][1]);
            indeg[edge[i][1]]++;
        }
        int c=0,ans;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){ans=i; c++;}
        }
        if(c>=2 || c==0) return -1;
        return ans;
    }
};
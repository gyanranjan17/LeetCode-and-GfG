class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        if(n==1 && grid[0][0]==0) return 1;
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int> (n,0));
        q.push({0,0});
        int count=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                if(r==n-1 && c==n-1)
                        return count+1;
                for(int i=-1;i<2;i++){
                    for(int j=-1;j<2;j++){
                    int nrow=r+i;
                    int ncol=c+j;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0 && !vis[nrow][ncol]){
                        
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                    }
                }   
            }
            count++;
        }
        return -1;
    }
};
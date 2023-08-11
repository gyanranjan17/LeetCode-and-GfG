class Solution {
public:
    int d[5]={-1,0,1,0,-1},res=0;
    bool dfs(int r,int c,vector<vector<int>>&grid,vector<vector<int>> &vis,int m){
        int n=grid.size();
        if(vis[r][c]<m) return 0;
        if(r==n-1 && c==n-1) return (vis[r][c]>=m);
        vis[r][c]=-1;
        for(int k=0;k<4;k++){
            int nr=r+d[k];
            int nc=c+d[k+1];
            if(nr>=0 && nr<n && nc>=0 && nc<n && vis[nr][nc]!=-1){
                if(dfs(nr,nc,grid,vis,m)) return 1;
            }
        }
        return 0;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> vis(n,vector<int>(n,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                q.push({i,j});
                vis[i][j]=0;
                }
            }
        }
        int cnt=0;
        while(!q.empty()){
            int sz=q.size();
            cnt++;
            while(sz--){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int nr=r+d[k];
                    int nc=c+d[k+1];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && vis[nr][nc]==-1){
                        q.push({nr,nc});
                        vis[nr][nc]=cnt;
                    }
                }
            }
        }
        int ans=vis[0][0];
        int i=0,j=cnt;
        while(i<=j){
            vector<vector<int>> v=vis;
            int m=(i+j)/2;
            if((dfs(0,0,grid,v,m))){
                ans=m;
                i=m+1;
            }
            else j=m-1;
        }
        return ans;
        // return res;
    }
};
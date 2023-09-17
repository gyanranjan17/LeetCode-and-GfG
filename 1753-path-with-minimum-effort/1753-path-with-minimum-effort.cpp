class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n=h.size(),m=h[0].size();
        queue<pair<pair<int,int>,int>> q;
        int d[]={-1,0,1,0,-1};
        q.push({{0,0},0});
        vector<vector<int>> eff(n,vector<int>(m,1e9));
        eff[0][0]=0;
        int ans=1e9;
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int dist=q.front().second;
            q.pop();
            if(x==n-1 && y==m-1) {
                ans=min(ans,dist);
                continue;
            }
            for(int k=0;k<4;k++){
                int nr=x+d[k];
                int nc=y+d[k+1];
                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    if(eff[nr][nc]>max(dist,abs(h[nr][nc]-h[x][y]))){
                        eff[nr][nc]=max(dist,abs(h[nr][nc]-h[x][y]));
                        q.push({{nr,nc},eff[nr][nc]});
                    }
                }
            }
        }
        return ans;
    }
};
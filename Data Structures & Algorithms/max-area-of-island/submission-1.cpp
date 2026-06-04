class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
    int bfs(int a,int b,vector<vector<int>> &grid,queue<pair<int,int>> &q){
        int c=0;
        q.push({a,b});
        grid[a][b]=0;

        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            c++;

            for(int i=0;i<4;i++){
                int r=x+dx[i],c=y+dy[i];
                if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && grid[r][c]==1){
                    q.push({r,c});
                    grid[r][c]=0;
                }
            }
        }
        return c;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)
                    ans=max(ans,bfs(i,j,grid,q));
            }
        }
        return ans;
    }
};

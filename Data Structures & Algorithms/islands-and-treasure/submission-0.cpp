class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int dx[]={0,0,-1,1};
        int dy[]={-1,1,0,0};

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0)
                    q.push({{i,j},0});
            }
        }
        
        while(!q.empty()){
            auto [inner,steps]=q.front();
            auto [x,y]=inner;
            q.pop();

            for(int i=0;i<4;i++){
                int r=x+dx[i];
                int c=y+dy[i];
                if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && grid[r][c]==INT_MAX){
                    grid[r][c]=steps+1;
                    q.push({{r,c},steps+1});
                }
            }

        }
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int f=0,min=-1;
        queue<pair<int,int>> q;
        int dx[]={0,0,-1,1};
        int dy[]={-1,1,0,0};

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)
                    f++;
                else if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        if(f==0)
            return 0;

        while(!q.empty()){
            int n=q.size();
            min++;
            for(int i=0;i<n;i++){
                auto [x,y]=q.front();
                q.pop();

                for(int j=0;j<4;j++){
                    int r=x+dx[j],c=y+dy[j];
                    if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && grid[r][c]==1){
                        grid[r][c]=2;
                        q.push({r,c});
                        f--;
                    }
                }
            }
        }
        if(f!=0)
            return -1;
        return min;
    }
};

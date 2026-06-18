class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dist(n,vector<int> (n,1e9));
        set<pair<int,pair<int,int>>> se;
        int dx[]={0,0,-1,1};
        int dy[]={-1,1,0,0};

        dist[0][0]=grid[0][0];
        se.insert({grid[0][0],{0,0}});

        while(!se.empty()){
            auto [t,coord]=*se.begin();
            auto [x,y]=coord;
            se.erase(se.begin());
            if(dist[x][y]<t) continue;

            for(int i=0;i<4;i++){
                int r=x+dx[i];
                int c=y+dy[i];

                if(r>=0 && r<n && c>=0 && c<n){
                    int maxTime=max(t,grid[r][c]);
                    if(maxTime<dist[r][c]){
                        dist[r][c]=maxTime;
                        se.insert({maxTime,{r,c}});
                    }
                }
            }
        }

        return dist[n-1][n-1];

    }
};

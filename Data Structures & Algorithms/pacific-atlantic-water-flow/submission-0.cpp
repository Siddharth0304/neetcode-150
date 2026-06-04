class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
    bool bfs(int a,int b,vector<vector<int>> &heights){
        int pac=0,atl=0,n=heights.size(),m=heights[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int> (m,0));
        vis[a][b]=1;
        q.push({a,b});

        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            if(y==0 || x==0)
                pac++;
            if(y==m-1 || x==n-1)
                atl++;
            for(int i=0;i<4;i++){
                int r=x+dx[i],c=y+dy[i];
                if(r>=0 && c>=0 && r<n && c<m && heights[r][c]<=heights[x][y] && !vis[r][c]){
                    vis[r][c]=1;
                    q.push({r,c});
                }
            }
        }
        return pac>0 && atl>0;

    }   
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(bfs(i,j,heights))
                    ans.push_back({i,j});
            }
        }

        return ans;

    }
};

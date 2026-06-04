class Solution {
public:
    bool bfs(vector<vector<int>> &edges,int idx){
        int n=edges.size();
        vector<vector<int>> adj(n+1);
        vector<int> vis(n+1,0);
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(i==idx) continue;
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        q.push({1,-1});
        vis[1]=1;

        while(!q.empty()){
            auto [node,par]=q.front();
            q.pop();

            for(auto &it:adj[node]){
                if(!vis[it]){
                    q.push({it,node});
                    vis[it]=1;
                }
                else if(it!=par)
                    return false;
            }
        }
        for(int i=1;i<=n;i++){
            if(vis[i]==0)
                return false;
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        for(int i=0;i<edges.size();i++){
            if(bfs(edges,i))
                ans=edges[i];
        }
        return ans;
    }
};

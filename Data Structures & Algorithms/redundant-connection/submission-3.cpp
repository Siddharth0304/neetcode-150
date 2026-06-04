class Solution {
public:
    bool bfs(vector<vector<int>> &edges,vector<int> &edge,vector<vector<int>> &adj){
        int n=edges.size();
        vector<int> vis(n+1,0);
        queue<pair<int,int>> q;
        q.push({1,-1});
        vis[1]=1;

        while(!q.empty()){
            auto [node,par]=q.front();
            q.pop();

            for(auto &it:adj[node]){
                if((node==edge[0] && it==edge[1]) || (node==edge[1] && it==edge[0]))
                    continue;
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
        int n=edges.size();
        vector<int> ans;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<edges.size();i++){
            if(bfs(edges,edges[i],adj))
                ans=edges[i];
        }
        return ans;
    }
};

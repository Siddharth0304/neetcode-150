class Solution {
public:
    void bfs(int src,vector<int> &vis,vector<vector<int>> &adj,queue<int> &q){
        q.push(src);
        vis[src]=1;

        while(!q.empty()){
            auto node=q.front();
            q.pop();

            for(auto &it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        queue<int> q;
        int c=0;
        
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                c++;
                bfs(i,vis,adj,q);
            }
        }

        return c;
    }
};

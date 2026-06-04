class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        queue<pair<int,int>> q;
        q.push({0,-1});
        vis[0]=1;

        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

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
        for(auto &it:vis){
            if(it==0)
                return false;
        }
        return true;

    }
};

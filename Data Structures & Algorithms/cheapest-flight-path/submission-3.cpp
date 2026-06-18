class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<vector<int>> q;
        vector<int> dist(n,1e9);
        vector<vector<pair<int,int>>> adj(n);

        for(auto &it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        q.push({0,0,src});
        dist[src]=0;

        while(!q.empty()){
            auto f=q.front();
            q.pop();
            int curK=f[0];
            int d=f[1];
            int node=f[2];

            if(curK>k) continue;

            for(auto &it:adj[node]){
                if(d+it.second<dist[it.first]){
                    dist[it.first]=d+it.second;
                    q.push({curK+1,d+it.second,it.first});
                }
            }
        }
        if(dist[dst]==1e9)
            return -1;
        return dist[dst];
    }
};

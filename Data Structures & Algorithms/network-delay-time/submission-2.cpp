class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int ans=-1;
        vector<int> dist(n+1,1e8);
        vector<vector<pair<int,int>>> adj(n+1);
        set<pair<int,int>> se;
        dist[k]=0;
        se.insert({0,k});
        
        for(auto &it:times)
            adj[it[0]].push_back({it[1],it[2]});

        while(!se.empty()){
            auto [wt,node]=*se.begin();
            se.erase(se.begin());
            if(dist[node]<wt) continue;

            for(auto &it:adj[node]){
                if(wt+it.second<dist[it.first]){
                    dist[it.first]=wt+it.second;
                    se.insert({wt+it.second,it.first});
                }
            }
        }

        for(int i=1;i<=n;i++){
            ans=max(ans,dist[i]);
        }
        
        if(ans==1e8) return -1;
        return ans;
    }
};

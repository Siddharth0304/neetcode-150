class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,1e8);
        int ans=-1;
        dist[k]=0;
        for(int i=1;i<n;i++){
            for(auto &it:times){
                if(dist[it[0]]!=1e8 && dist[it[0]]+it[2]<dist[it[1]])
                    dist[it[1]]=dist[it[0]]+it[2];
            }
        }
        for(int i=1;i<=n;i++){
            ans=max(ans,dist[i]);
        }

        if(ans==1e8) return -1;
        return ans;
    }
};

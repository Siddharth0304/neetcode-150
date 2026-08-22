class Solution {
public:
    void dfs(string node,vector<int> &vis,vector<string> &ans,map<string,vector<pair<string,int>>> &mp){
        for(auto &it:mp[node]){
            if(vis[it.second]) continue;
            vis[it.second]=1;
            dfs(it.first,vis,ans,mp);
        }
        ans.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,vector<pair<string,int>>> mp;
        map<string,int> indegree,outdegree;
        vector<string> ans;
        vector<int> vis(tickets.size(),0);
        for(int i=0;i<tickets.size();i++){
            auto it=tickets[i];
            mp[it[0]].push_back({it[1],i});
            indegree[it[1]]++;
            outdegree[it[0]]++;
        }
        for(auto &it:mp)
            sort(it.second.begin(),it.second.end());
        dfs("JFK",vis,ans,mp);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
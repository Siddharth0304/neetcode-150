class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        vector<int> ans;
        queue<int> q;
        int c=0;

        for(auto &it:prerequisites){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                q.push(i);
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            c++;
            ans.push_back(node);

            for(auto &it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }

        if(c!=numCourses)
            return {};
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

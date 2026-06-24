class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        map<char,vector<char>> adj;
        string s;
        queue<char> q;

        for(auto &it:words){
            for(auto &i:it)
                adj.insert({i,{}});
        }

        map<char,int> indegree;

        for(int i=1;i<words.size();i++){
            string a=words[i-1];
            string b=words[i];
            int len=min(a.size(),b.size());
            bool flag=false;
            for(int i=0;i<len;i++){
                if(a[i]!=b[i]){
                    adj[a[i]].push_back(b[i]);
                    flag=true;
                    break;
                }
            }
            if(flag==false && a.size()>b.size())
                return "";
        }
        
        for(auto &it:adj){
            for(auto &i:it.second){
                indegree[i]++;
            }
        }

        for(auto &it:adj){
            if(indegree[it.first]==0)
                q.push(it.first);
        }

        while(!q.empty()){
            auto node=q.front();
            cout<<node<<endl;
            q.pop();
            s.push_back(node);

            for(auto &it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        // cout<<s<<endl;

        if(s.size()==adj.size())
            return s;
        return "";

    }
};

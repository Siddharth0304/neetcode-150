class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,vector<int>> mp;
        vector<vector<int>> v;
        vector<vector<int>> merge;
        vector<int> ans;

        for(int i=0;i<s.size();i++){
            if(mp[s[i]].size()!=0)
                mp[s[i]][1]=i;
            else
                mp[s[i]]={i,0};
        }
        for(auto &it:mp){
            v.push_back(it.second);
        }

        sort(v.begin(),v.end());
        merge.push_back(v[0]);
        for(int i=1;i<v.size();i++){
            if(v[i][0]>merge.back()[0] && v[i][0]<merge.back()[1])
                merge.back()[1]=max(merge.back()[1],v[i][1]);
            else
                merge.push_back(v[i]);
        }
        for(auto &it:merge){
            if(it[1]>0)
                ans.push_back(it[1]-it[0]+1);
            else
                ans.push_back(1);
        }
        return ans;
    }
};

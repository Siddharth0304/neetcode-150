class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> mp;
        vector<int> ans;
        for(int i=0;i<s.size();i++)
            mp[s[i]]=i;
        int i=0;
        while(i<s.size()){
            int k=i;
            int j=mp[s[i]];
            while(k<=j){
                j=max(j,mp[s[k]]);
                k++;
            }
            ans.push_back(j-i+1);
            i=k;
        }
        return ans;
    }
};

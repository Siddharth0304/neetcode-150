class Solution {
public:
    void dfs(map<char,string> &mp, string digits, int i, string temp, vector<string> &ans){
        if(i==digits.size()){
            if(temp.size()>0)
                ans.push_back(temp);
            return;
        }
        for(int j=0;j<mp[digits[i]].size();j++){
            temp.push_back(mp[digits[i]][j]);
            dfs(mp,digits,i+1,temp,ans);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        map<char,string> mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";

        vector<string> ans;
        dfs(mp,digits,0,"",ans);
        return ans;
    }
};

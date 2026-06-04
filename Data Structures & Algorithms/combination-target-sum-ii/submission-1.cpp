class Solution {
public:
    void func(vector<int>& candidates, set<vector<int>> &ans, vector<int> temp, int i, int s, int target){
        if(i==candidates.size()){
            if(s==target)
                ans.insert(temp);
            return;
        }
        temp.push_back(candidates[i]);
        func(candidates,ans,temp,i+1,s+candidates[i],target);
        temp.pop_back();
        func(candidates,ans,temp,i+1,s,target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        set<vector<int>> ans;
        func(candidates,ans,{},0,0,target);
        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
    }
};

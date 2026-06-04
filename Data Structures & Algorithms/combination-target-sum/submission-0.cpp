class Solution {
public:
    void func(set<vector<int>> &ans, vector<int> &temp, vector<int> &nums, int target, int i, int s){
        if(i==nums.size() || s>=target){
            if(s==target)
                ans.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        func(ans,temp,nums,target,i,s+nums[i]);
        func(ans,temp,nums,target,i+1,s+nums[i]);
        temp.pop_back();
        func(ans,temp,nums,target,i+1,s);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        set<vector<int>> ans;
        vector<int> temp;

        func(ans,temp,nums,target,0,0);
        vector<vector<int>> res;
        for(auto &it:ans)
            res.push_back(it);
        return res; 
    }
};

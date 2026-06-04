class Solution {
public:
    void func(vector<vector<int>> &ans, vector<int> &nums, vector<int> &temp,vector<int> &vis){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(vis[i])
                continue;
            temp.push_back(nums[i]);
            vis[i]=1;
            func(ans,nums,temp,vis);
            vis[i]=0;
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> vis(nums.size(),0);
        vector<int> temp;
        func(ans,nums,temp,vis);
        return ans;
    }
};

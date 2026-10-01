class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vis,v;
    int n;
    void helper(vector<int> &nums){
        if(v.size()==n){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=1;
                v.push_back(nums[i]);
                helper(nums);
                vis[i]=0;
                v.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        vis.resize(n,0);
        sort(nums.begin(),nums.end());
        helper(nums);
        return ans;
    }
};

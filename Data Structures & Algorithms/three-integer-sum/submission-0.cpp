class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> se;
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            int l=i+1,h=n-1;
            int k=0-nums[i];
            while(l<h){
                if(nums[l]+nums[h]>k)
                    h--;
                else if(nums[l]+nums[h]<k)
                    l++;
                else{
                    se.insert({nums[i],nums[l],nums[h]});
                    l++;
                    h--;
                }
            }
        }
        for(auto &it:se)
            ans.push_back(it);
        return ans;
    }
};

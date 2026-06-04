class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]>0)
                break;
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int l=i+1,h=n-1;
            int k=0-nums[i];
            while(l<h){
                if(nums[l]+nums[h]>k)
                    h--;
                else if(nums[l]+nums[h]<k)
                    l++;
                else{
                    ans.push_back({nums[i],nums[l],nums[h]});
                    l++;
                    h--;
                    while(l<h && nums[l]==nums[l-1])
                        l++;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        map<long long,vector<int>> mp;
        for(int i=0;i<n;i++)
            mp[nums[i]].push_back(i);
        
        set<vector<int>> se;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(i==j || i==k || j==k)
                        continue;
                    long long req=1LL*nums[i]+1LL*nums[j]+1LL*nums[k];
                    req=1LL*target-req;
                    for(auto &it:mp[req]){
                        if(i==it || j==it || k==it) continue;
                        vector<int> v={nums[i],nums[j],nums[k],nums[it]};
                        sort(v.begin(),v.end());
                        se.insert(v);
                    }
                }
            }
        }
        vector<vector<int>> ans(begin(se),end(se));
        return ans;
    }
};
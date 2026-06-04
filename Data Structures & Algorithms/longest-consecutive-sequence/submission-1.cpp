class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        sort(nums.begin(),nums.end());
        map<int,int> mp;
        int ans=0,c=1;

        for(int i=0;i<nums.size();i++)
            mp[nums[i]]=i;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]==0)
                continue;
            if(nums[i]-nums[i-1]==1)
                c++;
            else{
                ans=max(ans,c);
                c=1;
            }
        }

        return max(ans,c);
        
    }
};

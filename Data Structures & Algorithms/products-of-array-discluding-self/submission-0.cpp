class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        vector<int> ans(nums.size());

        int n=nums.size();

        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];

        for(int i=1;i<n;i++)
            prefix[i]=prefix[i-1]*nums[i];

        for(int i=n-2;i>=0;i--)
            suffix[i]=suffix[i+1]*nums[i];

        for(int i=0;i<n;i++){
            int l=i-1>=0?prefix[i-1]:1;
            int r=i+1<n?suffix[i+1]:1;
            ans[i]=l*r;
        }

        return ans;

    }
};

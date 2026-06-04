class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0,r=0,ans=0;
        while(r<nums.size()-1){
            int maxJump=0;
            for(int i=l;i<=r;i++)
                maxJump=max(maxJump,i+nums[i]);
            ans++;
            l=r+1;
            r=maxJump;
        }
        return ans;
    }
};

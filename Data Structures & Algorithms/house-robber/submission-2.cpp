class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size(),a=0,b=0;
        for(int i=n-1;i>=0;i--){
            int c=max(b,nums[i]+a);
            a=b;
            b=c;
        }
        return b;
    }
};

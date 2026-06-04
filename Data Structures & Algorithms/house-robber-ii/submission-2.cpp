class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        int a=0,b=0,c=0,d=0;
        for(int i=n-1;i>=1;i--){
            int x=max(b,nums[i]+a);
            a=b;
            b=x;
        }

        for(int i=n-2;i>=0;i--){
            int x=max(d,nums[i]+c);
            c=d;
            d=x;
        }

        return max(b,d);
    }
};

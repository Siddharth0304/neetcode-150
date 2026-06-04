class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=0,m=INT_MIN,n=INT_MAX;
        for(auto &it:nums){
            ans^=it;
            m=max(m,it);
            n=min(n,it);
        }
        for(int i=n;i<=m;i++)
            ans^=i;
        if(ans==0){
            if(n>0)
                return 0;
            return m+1;
        }
        return ans;
    }
};

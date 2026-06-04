class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,l=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]-prices[l]>0)
                ans=max(ans,prices[i]-prices[l]);
            else
                l=i;
        }
        return ans;
    }
};

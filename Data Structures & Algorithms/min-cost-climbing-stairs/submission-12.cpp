class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int a=0,b=cost[n-1];
        for(int i=n-2;i>=0;i--){
            int c=cost[i]+min(b,a);
            a=b;
            b=c;
        }
        return min(a,b);
    }
};

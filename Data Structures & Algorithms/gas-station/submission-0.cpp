class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totGas=0,ans=-1,n=gas.size();

        for(int i=0;i<2*n;i++){
            if(totGas+gas[i%n]>=cost[i%n]){
                if(ans==-1)
                    ans=i;
                totGas=totGas+gas[i%n]-cost[i%n];
            }
            else{
                ans=-1;
                totGas=0;
            }
        }
        if(ans>=n)
            return -1;
        return ans;
    }
};

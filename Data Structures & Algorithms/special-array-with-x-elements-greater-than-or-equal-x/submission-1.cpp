class Solution {
public:
    int specialArray(vector<int>& nums) {
        for(int i=1;i<=1000;i++){
            int c=0;
            for(auto &it:nums){
                if(it>=i)
                    c++;
            }
            if(c==i)
                return i;
        }
        return -1;
    }
};
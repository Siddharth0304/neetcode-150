class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> a;
        for(auto &it:nums){
            if(it%2==0)
                a.push_back(it);
        }

        for(auto &it:nums){
            if(it%2==1)
                a.push_back(it);
        }

        return a;
    }
};
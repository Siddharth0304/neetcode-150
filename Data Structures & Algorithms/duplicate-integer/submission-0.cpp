class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> se;
        for(auto &it:nums){
            if(se.find(it)!=se.end())
                return true;
            se.insert(it);
        }
        return false;
    }
};
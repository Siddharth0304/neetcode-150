class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        vector<int> a(n);
        int l=0,h=n-1;
        for(auto &it:nums){
            if(it%2==0){
                a[l]=it;
                l++;
            }
            else{
                a[h]=it;
                h--;
            }
        }

        return a;
    }
};
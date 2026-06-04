class Solution {
public:
    int bs(vector<int> &nums,int l,int h,int target){
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]>target)
                h=mid-1;
            else if(nums[mid]<target)
                l=mid+1;
            else
                return mid;
        }
        return -1;
    }
    int findMin(vector<int> &nums){
        int l=0,h=nums.size()-1;
        while(l<h){
            int mid=(l+h)/2;
            if(nums[mid]>nums[h])
                l=mid+1;
            else
                h=mid;
        }
        return l;
    }
    int search(vector<int>& nums, int target) {
        int m=findMin(nums);
        if(target>=nums[m] && target<=nums.back())
            return bs(nums,m,nums.size()-1,target);
        else
            return bs(nums,0,m-1,target);
    }
};

class Solution {
public:
    bool pos(vector<int>& piles,int h,int k){
        int c=0;
        for(auto &it:piles){
            int x=ceil(it/(double)k);
            c+=x;
        }
        if(c<=h)
            return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int s=1,e=piles.back();
        int ans=0;
        int totalBananas=0;
        while(s<=e){
            int mid=(s+e)/2;
            if(pos(piles,h,mid)){
                ans=mid;
                e=mid-1;
            }
            else
                s=mid+1;
        }
        return ans;
    }
};

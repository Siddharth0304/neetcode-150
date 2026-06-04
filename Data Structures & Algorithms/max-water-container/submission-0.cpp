class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0,h=heights.size()-1;
        int ans=0;
        while(l<h){
            int len=min(heights[l],heights[h]);
            int wid=h-l;
            ans=max(ans,len*wid);
            if(heights[l]<heights[h])
                l++;
            else
                h--;
        }
        return ans;
    }
};

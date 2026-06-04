class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int s=0;
        vector<int> preMax(n);
        vector<int> sufMax(n);
        preMax[0]=height[0];
        sufMax[n-1]=height[n-1];
        for(int i=1;i<n;i++)
            preMax[i]=max(preMax[i-1],height[i]);
        for(int i=n-2;i>=0;i--)
            sufMax[i]=max(sufMax[i+1],height[i]);
        for(auto &it:preMax)
            cout<<it<<" ";
        cout<<endl;
        for(auto &it:sufMax)
            cout<<it<<" ";
        for(int i=0;i<n;i++){
            if(preMax[i]!=-1 && sufMax[i]!=-1)
                s+=(min(preMax[i],sufMax[i])-height[i]);
        }
        return s;

    }
};

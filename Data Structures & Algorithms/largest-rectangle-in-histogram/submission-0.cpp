class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> nse(n,n);
        vector<int> pse(n,-1);
        stack<int> st;
        int ans=0;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            if(!st.empty())
                nse[i]=st.top();
            st.push(i);
        }
        st=stack<int>();
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            if(!st.empty())
                pse[i]=st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++){
            int x=(nse[i]-pse[i]-1)*heights[i];
            ans=max(ans,x);
        }
        return ans;
    }
};

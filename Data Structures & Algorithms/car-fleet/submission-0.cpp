class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> v;
        stack<double> st;
        int c=0;
        for(int i=0;i<position.size();i++){
            double x=(double)(target-position[i])/(double)(speed[i]);
            v.push_back({position[i],x});
        }
        sort(v.begin(),v.end());
        for(int i=v.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<v[i].second)
                st.pop();
            if(st.empty()){
                st.push(v[i].second);
                c++;
            }
        }
        return c;
    }
};
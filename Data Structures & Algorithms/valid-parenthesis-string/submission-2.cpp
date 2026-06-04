class Solution {
public:
    bool checkValidString(string s) {
        vector<int> v;
        stack<pair<char,int>> st;

        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                st.push({s[i],i});
            else if(s[i]=='*')
                v.push_back(i);
            else{
                if(!st.empty())
                    st.pop();
                else if(v.size()>0)
                    v.pop_back();
                else
                    return false;
            }
        }

        int i=v.size()-1;
        while(i>=0 && !st.empty()){
            if(v[i]>=st.top().second){
                st.pop();
                i--;
            }
            else
                return false;
        }
        if(st.empty())
            return true;
        return false;
    }
};

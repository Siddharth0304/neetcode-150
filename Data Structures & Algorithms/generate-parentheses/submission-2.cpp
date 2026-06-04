class Solution {
public:
    bool valid(string s){
        stack<char> st;
        for(auto &it:s){
            if(it=='(' || it=='{' || it=='[')
                st.push(it);
            else{
                if(st.empty())
                    return false;
                else if(st.top()=='(' && it==')')
                    st.pop();
                else if(st.top()=='{' && it=='}')
                    st.pop();
                else if(st.top()=='[' && it==']')
                    st.pop();
                else
                    return false;
            }
        }
        if(st.empty())
            return true;
        return false;
    }
    void gen(int n, int i, string s, vector<string> &ans){
        if(i==2*n){
            if(valid(s))
                ans.push_back(s);
            return;
        }
        gen(n,i+1,s+'(',ans);
        gen(n,i+1,s+')',ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        gen(n,0,"",ans);
        return ans;
    }
};

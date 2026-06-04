class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto &it:s){
            if(it=='(' || it=='{' || it=='[')
                st.push(it);
            else{
                if(!st.empty() && it==')' && st.top()=='(')
                    st.pop();
                else if(!st.empty() && it=='}' && st.top()=='{')
                    st.pop();
                else if(!st.empty() && it==']' && st.top()=='[')
                    st.pop();
                else 
                    return false;
            }
        }
        if(st.empty())
            return true;
        return false;
    }
};

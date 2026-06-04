class Solution {
public:
    void genPar(int n,int o,int c, string s, vector<string> &ans){
        if(o>n)
            return;
        if(o+c==2*n){
            ans.push_back(s);
            return;
        }
        genPar(n,o+1,c,s+'(',ans);
        if(c<o)
            genPar(n,o,c+1,s+')',ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        genPar(n,0,0,"",ans);
        return ans;
    }
};

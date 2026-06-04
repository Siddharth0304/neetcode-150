class Solution {
public:
    bool cond(map<char,int> &a,map<char,int> &b){
        for(auto &it:a){
            if(it.second>b[it.first])
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        map<char,int> a;
        map<char,int> b;
        pair<int,int> p;
        int l=0,ans=INT_MAX;
        for(auto &it:t)
            a[it]++;

        for(int i=0;i<s.size();i++){
            b[s[i]]++;
            while(cond(a,b)){
                if(i-l+1<ans){
                    ans=i-l+1;
                    p={l,i};
                }
                b[s[l]]--;
                l++;
            }
        }
        if(ans==INT_MAX)
            return "";
        return s.substr(p.first,p.second-p.first+1);        
    }
};

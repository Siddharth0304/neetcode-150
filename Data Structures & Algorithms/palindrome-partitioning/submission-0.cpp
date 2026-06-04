class Solution {
public:
    bool palindrome(string s){
        int l=0,h=s.size()-1;
        while(l<h){
            if(s[l]!=s[h])
                return false;
            l++;
            h--;
        }
        return true;
    }
    void func(vector<vector<string>> &ans, vector<string> &temp, string s, int i){
        if(i==s.size()){
            for(auto &it:temp){
                if(!palindrome(it))
                    return;
            }
            ans.push_back(temp);
            return;
        }

        for(int j=i;j<s.size();j++){
            string x=s.substr(i,j-i+1);
            // if(palindrome(x))
                temp.push_back(s.substr(i,j-i+1));
            func(ans,temp,s,j+1);
            // if(!temp.empty())
                temp.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        func(ans,temp,s,0);
        return ans;
    }
};

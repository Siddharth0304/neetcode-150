class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> c(26,0);
        vector<int> d(26,0);

        for(auto &it:s)
            c[it-'a']++;
        
        for(auto &it:t)
            d[it-'a']++;
        
        for(int i=0;i<26;i++){
            if(c[i]!=d[i])
                return false;
        }

        return true;
    }
};

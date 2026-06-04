class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> a(26,0);
        vector<int> b(26,0);
        int l=0,c=0;
        for(auto &it:s1)
            a[it-'a']++;
        for(int i=0;i<s2.size();i++){
            b[s2[i]-'a']++;
            c++;
            while(c>s1.size()){
                b[s2[l]-'a']--;
                c--;
                l++;
            }
            if(a==b)
                return true;
        }
        return false;
    }
};

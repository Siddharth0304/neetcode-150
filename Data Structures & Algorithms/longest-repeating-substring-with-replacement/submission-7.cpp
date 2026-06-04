class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,ans=0,maxChar=0;
        vector<int> c(26,0);
        for(int i=0;i<s.size();i++){
            c[s[i]-'A']++;
            maxChar=max(maxChar,c[s[i]-'A']);
            if(i-l+1-maxChar>k){
                c[s[l]-'A']--;
                l++;
            }
            if(i-l+1-maxChar<=k)
                ans=max(ans,i-l+1);            
        }
        return ans;
    }
};

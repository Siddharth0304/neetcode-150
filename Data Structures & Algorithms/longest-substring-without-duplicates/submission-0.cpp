class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int ans=0,l=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            while(mp[s[i]]>1){
                mp[s[l]]--;
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};

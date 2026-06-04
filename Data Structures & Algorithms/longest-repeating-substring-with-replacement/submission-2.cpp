class Solution {
public:
    bool cond(map<char,int> &mp,int k){
        if(mp.size()==1)
            return false;
        int m=0,s=0;
        for(auto &it:mp){
            m=max(m,it.second);
            s+=it.second;
        }
        if(s-m>k)
            return true;
        return false;
    }
    int characterReplacement(string s, int k) {
        map<char,int> mp;
        int l=0,ans=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            while(cond(mp,k)){
                mp[s[l]]--;
                if(mp[s[l]]==0)
                    mp.erase(s[l]);
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};

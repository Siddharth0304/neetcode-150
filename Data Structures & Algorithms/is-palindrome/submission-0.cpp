class Solution {
public:
    bool isPalindrome(string s) {
        int l=0,h=s.size()-1;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        while(l<=h){
            if(s[l]==' ' || isalnum(s[l])==0){
                l++;
                continue;
            }
            if(s[h]==' ' || isalnum(s[h])==0){
                h--;
                continue;
            }
            if(s[l]!=s[h])
                return false;
            l++;
            h--;
        }
        return true;
    }
};

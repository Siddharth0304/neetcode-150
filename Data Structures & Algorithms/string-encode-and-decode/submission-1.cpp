class Solution {
public:

    string encode(vector<string>& strs) {
        string s="";
        for(auto &it:strs)
            s+=it+"|";
        return s;
    }

    vector<string> decode(string s) {
        vector<string> output;
        string word="";
        for(auto &it:s){
            if(it!='|')
                word+=it;
            else{
                output.push_back(word);
                word="";
            }
        }
        return output;
    }
};

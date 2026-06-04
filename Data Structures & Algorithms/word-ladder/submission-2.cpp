class Solution {
public:
    bool helper(string a,string b){
        int c=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i])
                c++;
        }
        return c==1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> se;
        q.push({beginWord,1});
        se.insert(beginWord);

        while(!q.empty()){
            auto [word,steps]=q.front();
            q.pop();
            if(word==endWord) return steps;

            for(auto &it:wordList){
                if(helper(it,word) && se.find(it)==se.end()){
                    se.insert(it);
                    q.push({it,steps+1});
                }
            }
        }

        return 0;
    }
};

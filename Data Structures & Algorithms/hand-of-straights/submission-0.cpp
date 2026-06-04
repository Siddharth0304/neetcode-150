class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mp;
        sort(hand.begin(),hand.end());
        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++;
        }   

        for(int i=0;i<hand.size();i++){
            if(mp[hand[i]]==0)
                continue;
            for(int j=hand[i];j<hand[i]+groupSize;j++){
                if(mp[j]==0)
                    return false;
                mp[j]--;
            }
        }

        return true;
    }
};

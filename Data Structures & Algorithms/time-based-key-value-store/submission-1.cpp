class TimeMap {
public:
    map<string,vector<pair<string,int>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string,int>> nums=mp[key];
        int l=0,h=nums.size()-1;
        int ans=-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid].second<=timestamp){
                ans=mid;
                l=mid+1;
            }
            else
                h=mid-1;
        }
        if(ans==-1)
            return "";
        return nums[ans].first;
    }
};

class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        int low = 0, high = m[key].size()-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(m[key][mid].first <= timestamp) low = mid+1;
            else high = mid-1;
        }
        if(high == -1) return "";
        return m[key][high].second;
    }
};
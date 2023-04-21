class UndergroundSystem {
public:
    
    map<int,pair<string,int>> checkin;
    map<pair<string,string>,vector<int>> getavgs;
    
    UndergroundSystem() {
        checkin.clear();
        getavgs.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        checkin[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string departure_station = checkin[id].first;
        int departure_time = checkin[id].second;
        
        int total_time = t - departure_time;
        getavgs[{departure_station,stationName}].push_back(total_time);
    }
    
    double getAverageTime(string startStation, string endStation) {
        
        pair<string,string> p = {startStation,endStation};
        vector<int> v = getavgs[p];
        int n = v.size();
        int s = 0;
        
        for(int i=0 ; i<n ; ++i) s += v[i];
        return double(s / (n * 1.0));
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
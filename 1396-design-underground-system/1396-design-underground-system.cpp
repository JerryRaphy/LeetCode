class UndergroundSystem {
public:
    
    map<int,pair<string,int>> checkin;
    map<pair<string,string>,pair<int,int>> getavgs;
    
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
        
        if(getavgs.find({departure_station,stationName}) == getavgs.end()){
            getavgs[{departure_station,stationName}] = {total_time,1};
            return;
        }
        
        getavgs[{departure_station,stationName}].first += total_time;
        getavgs[{departure_station,stationName}].second += 1;
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        
        pair<int,int> p = getavgs[{startStation,endStation}];
        return double(p.first / (p.second * 1.0));
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
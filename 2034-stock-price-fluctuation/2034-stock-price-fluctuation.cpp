class StockPrice {
public:
    
    
    map<int,int> prices;
    map<int,int> mp;
    priority_queue<int,vector<int>> times;
    priority_queue<int,vector<int>> get_max;
    priority_queue<int,vector<int>,greater<int>> get_min;
    
    
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        
        prices[price]++;
        get_max.push(price);
        get_min.push(price);
        
        
        if(mp.find(timestamp) != mp.end()){
            
            int prev_price = mp[timestamp];
            mp[timestamp] = price;
            
            prices[prev_price]--;
            if(prices[prev_price] == 0) prices.erase(prev_price);
            
            return;
        }
        
        times.push(timestamp);
        mp[timestamp] = price;
        return;
    }
    
    int current() {
        if(!times.empty()) return mp[times.top()];
        return 0;
    }
    
    int maximum() {
        while(!get_max.empty()){
            int curr_price = get_max.top();
            if(prices.find(curr_price) != prices.end()) break;
            get_max.pop();
        }
        return get_max.top();
    }
    
    int minimum() {
        while(!get_min.empty()){
            int curr_price = get_min.top();
            if(prices.find(curr_price) != prices.end()) break;
            get_min.pop();
        }
        return get_min.top();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
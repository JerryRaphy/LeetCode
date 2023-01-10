class DataStream {
public:
    
    int cnt = 0;
    int val,sz;
    
    
    DataStream(int value, int k) {
        val = value;
        sz = k;
    }
    
    bool consec(int num) {
        if(num == val){
            ++cnt;
            if(cnt >= sz) return true;
            return false;
        }
        else{
            cnt = 0;
            return false;
        }
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
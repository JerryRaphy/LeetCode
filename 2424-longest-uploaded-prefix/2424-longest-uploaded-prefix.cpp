class LUPrefix {
public:
    
    vector<bool> uploaded;
    int i;
    int m;
    
    LUPrefix(int n) {
        m = n;
        i = 0;
        uploaded.resize(n+1,false);
    }
    
    void upload(int video) {
        uploaded[video] = true;
        while(i<m && uploaded[i+1] == true) ++i;
    }
    
    int longest() {
        return i;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
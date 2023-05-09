class FrequencyTracker {
public:
    
    vector<int> freq;
    vector<int> numbers;
    
    FrequencyTracker() {
        numbers.resize(1e5+1,0);
        freq.resize(1e5+1,0);
    }
    
    void add(int number) {
        
        //decrement current freq;
        int curr_freq = numbers[number];
        freq[curr_freq] = max(0,freq[curr_freq] - 1);
        
        numbers[number]++;
        curr_freq = numbers[number];
        freq[curr_freq]++;
        
    }
    
    void deleteOne(int number) {
           
        
        if(numbers[number] <= 0) return;
        
         // decrement current freq
        int curr_freq = numbers[number];
        freq[curr_freq] = max(0,freq[curr_freq] - 1);
        
        numbers[number]--;
        curr_freq = numbers[number];
        freq[curr_freq]++;
        
    
    }
    
    bool hasFrequency(int frequency) {
        if(freq[frequency]) return true;
        return false;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
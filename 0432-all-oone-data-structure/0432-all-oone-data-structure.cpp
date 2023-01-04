class Node{
    
    public: 
    Node *front;
    Node *back;
    int freq;
    set<string> st;

    Node(){
        front = NULL;
        back = NULL;
        freq = 0;
    }
};


class AllOne {
public:
    
    Node *head;
    Node *tail;
    map<string,Node*> mp;
    
    AllOne() {
        head = new Node();
        tail = new Node();
        mp.clear();
        
        head->front = tail;
        tail->back = head;    
    }
    
    void inc(string key) {
         if(mp.find(key) == mp.end()){
            
              if(head->front == tail){
                Node *temp = new Node();
                temp->freq = 1;
                temp->st.insert(key);

                temp->back  = head;
                temp->front = tail;

                head->front = temp;
                tail->back  = temp;

                mp[key] = temp;
	          }   
              else if(head->front->freq != 1){
                 Node *temp = new Node();
                 temp->freq = 1;
                 temp->st.insert(key);
                  
                 temp->front = head->front;
                 temp->back = head;
                  
                 temp->front->back = temp;
                 head->front = temp;
                  
                  mp[key] = temp;
              }
              else{
                Node *temp = head->front;
                temp->st.insert(key);

                mp[key] = temp;
              }   
             
             
            
        }
        else{
            
            Node *temp = mp[key];
            int curr_freq = temp->freq;
            
        

            if(temp->front == tail){
                
                
                Node *f = new Node();
                f->freq = curr_freq + 1;
                f->st.insert(key);

                f->back  = temp;
                f->front = tail;

                temp->front = f;
                tail->back  = f;

                mp[key] = f;
            }
            else if((temp->front->freq - curr_freq) > 1){
                Node *f = new Node();
                f->freq = curr_freq + 1;
                f->st.insert(key);

                f->back  = temp;
                f->front = temp->front;

                temp->front = f;
                f->front->back = f;

                mp[key] = f;
            }
            else{
                temp->front->st.insert(key);
	            mp[key] = temp->front;

            }
            
            temp->st.erase(key);
            if(temp->st.empty()){
                temp->front->back = temp->back;
                temp->back->front = temp->front;
            }
              
       }
    }
    
    void dec(string key) {
        Node *temp = mp[key];
        int curr_freq = temp->freq;
        
        if(curr_freq == 1){
            temp->st.erase(key);
            mp.erase(key);
        }
        else if(temp->back == head){
            Node *f = new Node();
            f->freq = curr_freq - 1;
            f->st.insert(key);
            
            f->front = temp;
            f->back = head;
            
            head->front = f;
            temp->back = f;
            
            mp[key] = f;
        }
        else if((curr_freq - temp->back->freq) > 1){
            Node *f = new Node();
            f->freq = curr_freq - 1;
            f->st.insert(key);
            
            
            f->front = temp;
            f->back  = temp->back;
            
            f->back->front = f;
            temp->back = f;
            
            mp[key] = f;
        }
        else{
            temp->back->st.insert(key);
            mp[key] = temp->back;
        }
        
        temp->st.erase(key);
        if(temp->st.empty()){
            temp->back->front = temp->front;
            temp->front->back = temp->back;
        }
    }
    
    string getMaxKey() {
        
        if(mp.empty()) return "";
        string s = *(tail->back->st.begin());
        return s;
    }
    
    string getMinKey() {
        
        if(mp.empty()) return "";
        string s = *(head->front->st.begin());
        return s;

    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
struct Node{
    
    int key;
    int val;
    int cnt;
    Node *left;
    Node *right;    
    
    Node(int _key, int _val){
        key = _key;
        val = _val;
        left = NULL;
        right = NULL;
        cnt = 1;
    }  
};

struct NodeList{
    
    Node *head = new Node(0,0);
    Node *tail = new Node(0,0);
    int size;
    
    NodeList(){
        head->right = tail;
        tail->left = head;
        size = 0;
    }
    
    void addtofront(Node *node){
        size += 1;         
        node->right = head->right;
        node->right->left = node;
        
        head->right = node;
        node->left = head;
    }
    
    void remove(Node *node){
        size -= 1;
        node->right->left = node->left;
        node->left->right = node->right;
    }
    
};


class LFUCache {

    private: 
    
    map<int,Node*> keynode;
    map<int,NodeList*> freqlist;
    int maximum_capacity;
    int current_capacity;
    int min_freq;
    
    public:
    
    LFUCache(int capacity) {
        maximum_capacity = capacity;
        current_capacity = 0;
        min_freq = 0;
    }
    
    void changefrequencylist(Node *node){
        
        //remove from the corresponding dll
        NodeList *currentlist = freqlist[node->cnt];
        currentlist->remove(node);
        
        //check if dll is empty and the dll contained the minfrequent elements
        if(node->cnt == min_freq && currentlist->size == 0) min_freq += 1;
        
        //increment freq of current node
        node->cnt += 1;
        
        // initilize the newlist if not already existing
        NodeList *newlist;
        if(freqlist.count(node->cnt)) newlist = freqlist[node->cnt];
        else{
            newlist = new NodeList();
            freqlist[node->cnt] = newlist;
        }
        
        // add node into newlist
        newlist->addtofront(node);
        
    }
    
    int get(int key) {
        if(keynode.count(key)){
            Node *node = keynode[key];
            int val = node->val;
            changefrequencylist(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        
        if(maximum_capacity == 0) return;
        
        // if the key already exists and we just have to update the value
        if(keynode.count(key)){
            Node *node = keynode[key];
            node->val = value;
            changefrequencylist(node);
            return;
        }
        
        // if our cache if full we need to first delete the last element of minfreq list
        if(current_capacity == maximum_capacity){
            NodeList *currentlist = freqlist[min_freq];
            keynode.erase(currentlist->tail->left->key);
            currentlist->remove(currentlist->tail->left);
            current_capacity -= 1;
        }
        
        // if the key does not exist we need to create a new node and add to corresponding list
        Node *node = new Node(key,value);
        
        // minfreq changes to 1
        min_freq = 1;
        
        // update keynode map
        keynode[key] = node;
        
        // add to list
        NodeList *newlist;
        if(freqlist.count(node->cnt)) newlist = freqlist[node->cnt];
        else{
            newlist = new NodeList();
            freqlist[node->cnt] = newlist;
        }
        
        // add node into newlist
        newlist->addtofront(node);
        
        // increment currentcap
        current_capacity += 1;
        
        return;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
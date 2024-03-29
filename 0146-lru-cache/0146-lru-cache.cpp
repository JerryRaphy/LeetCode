class LRUCache {
public:
    
    class Node{
        
        public:
        int key;
        int val;
        Node *left;
        Node *right;

        Node(int k, int v){
            key = k;
            val = v;
            left = NULL;
            right = NULL;
        }
    };
    
    Node *head = new Node(0,0);
    Node *tail = new Node(0,0);
    int cap;
    unordered_map<int,Node*> mp;

    
    LRUCache(int capacity) {
        head->right = tail;
        tail->left = head;
        cap = capacity;
        mp.clear();
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;

        Node *curr = mp[key];
        remove(curr);
        insert(curr);
        return curr->val;
    }
    
    void remove(Node *curr){
        curr->right->left = curr->left;
        curr->left->right = curr->right;
    }
    
    
    void insert(Node *curr) {
        curr->right = head->right;
        curr->left  = head;

        head->right = curr;
        curr->right->left = curr;
    }
    
    void put(int key, int value) {
        
        if(mp.count(key)){
            Node *curr = mp[key];
            curr->val = value;
    
            remove(curr);
            insert(curr);
        }
        else{
            if(cap == 0){
                mp.erase(tail->left->key);
                remove(tail->left);
            }
            else cap -= 1;

            Node *curr = new Node(key,value);
            mp[key] = curr;
            insert(curr);  
        }
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
class MyQueue {
public:
    
    stack<int> st1;
    stack<int> st2;
    
    MyQueue() {
        while(!st1.empty()) st1.pop();
        while(!st2.empty()) st2.pop();
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    void putst1(){
         while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    void putst2(){
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
    }
            
    int pop() {
        putst2();
        int val = st2.top();
        st2.pop();
        putst1();
        return val;
    }
    
    int peek() {
        putst2();
        int val = st2.top();
        putst1();
        return val;
    }
    
    bool empty() {
        if(st1.empty()) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
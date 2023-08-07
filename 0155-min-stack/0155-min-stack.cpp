class MinStack {
public:
    
    
    stack<int> st;
    stack<int> mnst;
    
    MinStack() {
        while(!st.empty())   st.pop();
        while(!mnst.empty()) mnst.pop();
    }
    
    void push(int val) {
        st.push(val);
        if(mnst.empty()) mnst.push(val);
        else{
            if(val < mnst.top()) mnst.push(val);
            else mnst.push(mnst.top());
        }
    }
    
    void pop() {
        if(!st.empty()){
            st.pop();
            mnst.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mnst.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
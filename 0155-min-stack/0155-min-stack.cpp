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
      else if(val <= mnst.top()) mnst.push(val);
    }
    
    void pop() {
      if(st.empty()) return;
      if(!mnst.empty() && mnst.top() == st.top()) mnst.pop();
      st.pop();
      return;  
    }
    
    int top() {
      if(st.empty()) return 1;
      return st.top();
    }
    
    int getMin() {
      if(mnst.empty()) return -1;
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
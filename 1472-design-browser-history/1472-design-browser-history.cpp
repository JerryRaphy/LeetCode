class BrowserHistory {
public:
    
    stack<string> curr_page;
    stack<string> forward_page;
    
    BrowserHistory(string homepage) {
        curr_page.push(homepage);
    }
    
    void visit(string url) {
        while(!forward_page.empty()) forward_page.pop();
        curr_page.push(url);
    }
    
    string back(int steps) {
        
        for(int i=1 ; i<=steps ; ++i){
            if(curr_page.size() == 1){
                return curr_page.top();
            }
            else{
                string page = curr_page.top();
                curr_page.pop();
                forward_page.push(page);
            }
        }
        return curr_page.top();
        
    }
    
    string forward(int steps) {
        
        for(int i=1 ; i<=steps ; ++i){
             if(!forward_page.empty()){
                string page = forward_page.top();
                forward_page.pop();
                curr_page.push(page);
            }
        }
        return curr_page.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
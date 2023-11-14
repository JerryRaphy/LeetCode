class Solution {
public:
    
    class Node{
        
        public:
            
        bool isend;
        vector<Node*> freq;
        int cnt;
    
        Node(){
            isend = false;
            cnt = 0;
            freq.resize(26,NULL);
        }  
        
        void add(char ch){
            Node *child = new Node();
            this->freq[ch - 'a'] = child;
        }
        
    };
    
    
    void construct(Node *root, string s){
        
        int len = s.length();
            
        for(int i=0 ; i<len ; ++i){
            char ch = s[i];
            
            if(root->freq[ch - 'a'] == NULL){
                root->add(ch);
                root->cnt += 1;
            }
            root = root->freq[ch - 'a'];
        }
        root->isend = true;
    }
    
    
    void dfs(Node *root, string &res){
        
        if(root->cnt > 1 || root->isend) return;
        
        
        for(int i=0 ; i<26 ; ++i){
            if(root->freq[i] != NULL){
               res.push_back(char(i + 97));
               dfs(root->freq[i],res); 
            }
        }
                
        return;
    }
    
    string longestCommonPrefix(vector<string>& s) {
        
        int n = s.size();
        Node *root = new Node();
        
        for(int i=0 ; i<n ; ++i){
            if(s[i] == "") return "";
            construct(root,s[i]);
        }
            
        string res;
        dfs(root,res);
        
        return res;
        
    }
};
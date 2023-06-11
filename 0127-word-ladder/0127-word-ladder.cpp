class Solution {
public:
    int ladderLength(string A, string B, vector<string>& C) {
        
        set<string> dictionary;
        for(auto word : C) dictionary.insert(word);

        set<string> visited;
        queue<pair<string,int>> q;
        q.push({A,1});


        // if not present at all
        if(dictionary.find(B) == dictionary.end()) return 0;

        while(!q.empty()){
            string s = q.front().first;
            int t = q.front().second;
            q.pop();

            if(s == B) return t;

            int n = s.length();

            for(int i=0 ; i<n ; ++i){
                char original_ch = s[i];
                for(int j=0 ; j<26 ; ++j){
                    char changed_ch = char(j + 97);
                    if(changed_ch == original_ch) continue;
                    s[i] = changed_ch;

                    if(visited.find(s) == visited.end()){
                        if(dictionary.find(s) != dictionary.end()){
                            visited.insert(s);
                            q.push({s,t+1});
                        }
                    } 
                }
                s[i] = original_ch;
            }
        }
        
        return 0;     
    }   
};
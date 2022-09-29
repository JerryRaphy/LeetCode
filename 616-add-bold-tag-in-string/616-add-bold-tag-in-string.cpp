class Solution {
public:
    
    
    vector<pair<int,int>> getintervals(string s, vector<string> &words){
        vector<pair<int,int>> f;
        for(string word : words){
            int n = word.length();
            // the word can have multiple occurences 
            for(int i=0 ; (i = s.find(word,i)) != string::npos ; i++){
                f.push_back({i,i+n});
            }
        }
        return f;
    }
    
    
    static bool comp(pair<int,int> A, pair<int,int> B){
        if(A.first == B.first)
             return A.second < B.second;
        return A.first < B.first;
    }
    
    vector<pair<int,int>> mergeintervals(vector<pair<int,int>> &v){
        sort(v.begin(),v.end(),comp);
        vector<pair<int,int>> prev;
        int i = 0;
        int j = -1;
        int n = v.size();
        
        while(i < n){
            if(j < 0 || v[i].first > prev[j].second){
                prev.push_back(v[i]);
                ++j;
            }
            else{
                prev[j].second = max(prev[j].second,v[i].second);
            }
            ++i;
        }
        return prev;
    }
    
    string addBoldTag(string s, vector<string>& words) {
        vector<pair<int,int>> v = getintervals(s,words);
        v = mergeintervals(v);
        
         
       /* for(int i=0 ; i<v.size() ; ++i){
            cout<<v[i].first<<" "<<v[i].second<<endl;
        }*/
        
        for(auto it = v.rbegin() ; it != v.rend() ; it++){
            s.insert(it->second,"</b>");
            s.insert(it->first,"<b>");    
        }
        return s;
    }
};


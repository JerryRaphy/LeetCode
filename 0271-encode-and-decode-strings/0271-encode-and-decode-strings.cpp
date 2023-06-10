class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& s) {
        
        int n = s.size();
        string res;
        
        for(int i=0 ; i<n ; ++i){
            res += to_string(s[i].length());
            res.push_back('|');
            res += s[i];
        }
      
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int n = s.length();
        int l = 0;
        int r = 0;
        while(r < n){
            while(r < n && s[r] != '|') r += 1;
            int len = stoi(s.substr(l,r-l));
            res.push_back(s.substr(r+1,len));
            l = r + len + 1;
            r = l;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
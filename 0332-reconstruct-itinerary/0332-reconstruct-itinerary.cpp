class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        int n = tickets.size();
        map<string,multiset<string>> mp;
        
        for(int i=0 ; i<n ; ++i){
            mp[tickets[i][0]].insert(tickets[i][1]);
        }
        
        stack<string> st;
        st.push("JFK");
        
        vector<string> itinerary;
        
        while(!st.empty()){
            
            string curr = st.top();
            if(mp[curr].size() == 0){
                itinerary.push_back(curr);
                st.pop();
            }
            else{
                auto dest = (mp[curr].begin());
                st.push(*dest);
                mp[curr].erase(dest);
            }
            
        }
        
        reverse(itinerary.begin(),itinerary.end());
        return itinerary;
        
    }
};
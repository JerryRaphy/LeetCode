//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    bool static comp(pair<int,int> &A, pair<int,int> &B){
        if(A.second == B.second) return A.first < B.first;
        return A.second < B.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> v;
        for(int i=0 ; i<n ; ++i) v.push_back({start[i],end[i]});
        
        sort(v.begin(),v.end(),comp);
        
        
        int rooms = 1;
        int curr_end = v[0].second;
        
        for(int i=1 ; i<n ; ++i){
            if(v[i].first > curr_end){
                rooms += 1;
                curr_end = v[i].second;
            }
        }
        
        return rooms;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
class Solution {
public:
    vector<long long> getDistances(vector<int>& v) {
        
        int m = v.size();
        vector<long long> res(m,0);

        map<int,vector<long long>> mp;
        
        for(int i=0 ; i<m ; ++i){
            mp[v[i]].push_back(i);
        }
        
        for(auto it : mp){
            
            vector<long long> prefix = it.second;
            int n = prefix.size();

            for(int i=1 ; i<n ; ++i){
                prefix[i] += prefix[i-1];
            }

            long long running_sum = 0;

            for(int i=0 ; i<n ; ++i){
                long long curr = 0;
                if(i != n-1) curr += abs( (prefix[n-1] - prefix[i]) - (it.second[i] * ((n - 1)- i)) );
                if(i != 0) curr += abs( (i * it.second[i]) - running_sum);

                res[it.second[i]] = curr;
                running_sum += it.second[i];
            }
            
        }
        
        return res;
        
    }
};
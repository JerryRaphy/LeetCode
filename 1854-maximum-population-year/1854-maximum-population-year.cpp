class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        
        map<int,int> mp;
        for(auto log : logs) {
            mp[log[0]] += 1;
            mp[log[1]] -= 1;
        }
        
        int count = 0;  // running count of population 
        int maxCount = 0;   // max population
        int minYear;    // min year with max population
        for(auto &iter : mp)
        {
            count+=iter.second;
            if(count>maxCount)
            {
                maxCount = count;
                minYear = iter.first;
            }
        }
        
        return minYear;
    }
};
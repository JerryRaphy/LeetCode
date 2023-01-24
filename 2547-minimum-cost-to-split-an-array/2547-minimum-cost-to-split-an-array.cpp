class Solution {
public:


int minCost(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {

        unordered_map<int, int> mp;
        int co = 0;

        for (int j = i; j < n; j++)
        {
            mp[arr[j]]++;
            if (mp[arr[j]] == 2)
            {
                co += 2;
            }
            if (mp[arr[j]] > 2)
            {
                co++;
            }

            dp[i] = min(dp[i], k + dp[j + 1] + co);
        }
    }
    return dp[0];
}
};
class Solution {
public:
    class trie {
        public:
            unordered_map < int , trie* > next;
            trie() {
            }
    };
    
    
    int countDistinct(vector<int>& nums, int k, int p) {
        trie *root = new trie();
        int n = nums.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            
            // Temp Pointer, which copies the root.
            trie *temp = root;
            
            // Count stores total number divisible by 'P' so far.
            int count = 0;
            for(int j = i;j<n;j++){
                if(nums[j] % p == 0)
                    count++;
                
                // If count is greater than 'K' we do not have valid subarray. 
                if(count > k)
                    break;
                
                // Else if we do not have already existing node for new insertion we will create one.
                // Also increase 'ANS' by '1' as we encountered this position first time.
                if(!temp->next[nums[j]]){
                    temp->next[nums[j]] = new trie();
                    ans++;
                }
                temp = temp->next[nums[j]];
            }
        }
        return ans;
    }
};
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        
        int n = tokens.size();
        sort(tokens.begin(),tokens.end());
        int i = 0, j = n - 1;
        int score = 0;
        while( i <= j ){
            if( tokens[i] <= P) {
                score++;
                P -= tokens[i++];
            }
            else if ( score >= 1 && i < j){
                score--;
                P += tokens[j--];
            }
            else break;
        }
        return score;
        
    }
};
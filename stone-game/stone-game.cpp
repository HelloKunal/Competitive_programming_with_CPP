class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int numPiles = piles.size();
        int DP[numPiles][numPiles];
        
        for(int g = 0; g < numPiles; g++) {
            for(int i = 0, y = g; y < numPiles; i++, y++) {
                if(g == 0) DP[i][y] = piles[i];
                else if(g == 1) DP[i][y] = max(piles[i], piles[y]);
                else {
                    int val1 = piles[i] + min(DP[i+1][y-1], DP[i+2][y]);
                    int val2 = piles[y] + min(DP[i+1][y-1], DP[i][y-2]);
                    DP[i][y] = max(val1, val2);
                }
            }
        }
        
        return DP[0][numPiles-1];
    }
};
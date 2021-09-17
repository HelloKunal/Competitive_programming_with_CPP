class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int xAxis = mat[0].size();
        int yAxis = mat.size();
        vector<vector<int>> pSum(yAxis, vector<int> (xAxis, 0));
        for(int y = 0; y < yAxis; y++) {
            pSum[y][0] = mat[y][0];
            for(int x = 1; x < xAxis; x++) {
                pSum[y][x] = pSum[y][x-1] + mat[y][x];
            }
        }
        
        for(int y = 0; y < yAxis; y++) {
            for(int x = 0; x < xAxis; x++) {
                
                int nx2 = min(xAxis-1, x+k);
                int nx1 = x-k-1;
                int sum = 0;
                for(int ny = y - k; ny <= y + k; ny++) {
                    if(ny < 0 || ny > yAxis-1) continue;
                    if(nx1 < 0) sum += pSum[ny][nx2];
                    else sum += pSum[ny][nx2] - pSum[ny][nx1];                        
                }              
                
                mat[y][x] = sum;
            }
        }
        
        return mat;
    }
};
class NumMatrix {
public:
    vector<vector<int>> mat; 
    NumMatrix(vector<vector<int>>& matrix) {
        int xAxis = matrix[0].size();
        int yAxis = matrix.size(); 
        mat.assign(yAxis, vector<int>(xAxis));
        for(int y = 0; y < yAxis; y++) {
            for(int x = 0; x < xAxis; x++) {
                if(x == 0) mat[y][x] = matrix[y][x];
                else mat[y][x] = mat[y][x-1] + matrix[y][x];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int y = row1; y <= row2; y++) {
            if(col1 == 0) sum += mat[y][col2];
            else sum += mat[y][col2] - mat[y][col1-1];
        }
        
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
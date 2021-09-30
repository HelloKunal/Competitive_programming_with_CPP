class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        for(vector<int> mat : matrix) {
            if(binary_search(mat.begin(), mat.end(), target)) {
                return true;
            }
        }
        
        return false;
    }
};
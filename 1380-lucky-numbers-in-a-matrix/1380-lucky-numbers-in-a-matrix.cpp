class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> row_mini(rows,INT_MAX);
        vector<int> col_mini(cols,0);

        for(int row_ind = 0;row_ind<rows;++row_ind){
            for(int col_ind = 0;col_ind<cols;++col_ind){
                int el = matrix[row_ind][col_ind];
                row_mini[row_ind] = min(row_mini[row_ind], el);
                col_mini[col_ind] = max(col_mini[col_ind], el);
            }
        }

        for(int row_ind = 0;row_ind<rows;++row_ind){
            for(int col_ind = 0;col_ind<cols;++col_ind){
                int el = matrix[row_ind][col_ind];
                if(el == row_mini[row_ind] && el == col_mini[col_ind]) return {el};
            }
        }
        return {};
    }
};
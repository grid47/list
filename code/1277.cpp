class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int res = 0, m = matrix.size(), n = matrix[0].size();

        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] && i && j)
            matrix[i][j] += min({matrix[i - 1][j], matrix[i -1][j-1], matrix[i][j -1]});
            res += matrix[i][j];
        }
        return res;
    }
};
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& mat) {
        int n = mat.size();
        

        long long sum = 0;
        bool isodd = n % 2;
        int cnt = 0;
        int mn = abs(mat[0][0]);
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            
            if(mat[i][j] < 0) cnt++;
            
            mn = min(mn, abs(mat[i][j]));
            sum += abs(mat[i][j]);            
        }

        if(cnt%2 == 1)
            sum -= (2 *mn);
        
        return sum;
    }
};
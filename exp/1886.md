class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        for(int i = 0; i < 4; i++) {
            if(match(mat, target)) return true;
            rotate(mat);
        }
        return false;
    }
    
    void rotate(vector<vector<int>>& mtx) {
        int n= mtx.size();
        int i = 0, j = n - 1;
        while(i <= j)
            swap(mtx[i++], mtx[j--]);
        for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            swap(mtx[i][j], mtx[j][i]);
    }
    
    bool match(vector<vector<int>>& mtx1, vector<vector<int>>& mtx2) {
        int n = mtx1.size();
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(mtx1[i][j] != mtx2[i][j])
                return false;
        return true;
    }
};
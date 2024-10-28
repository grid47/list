class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        
        int l = 0, r = n - 1;
        
        while(l <= r) {
            int mid = l + (r - l + 1) / 2;
            
            int row = 0;
            for(int i = 0; i < m; i++)
                row = mat[i][mid] >= mat[row][mid]? i: row;
            
            int isRightLarger = mid + 1 <= r ? mat[row][mid + 1] > mat[row][mid]: false;
            int isLeftLarger = mid - 1 >= l  ? mat[row][mid - 1] > mat[row][mid]: false;            
            
            if(!isRightLarger && !isLeftLarger)
                return vector<int>{row, mid};
            
            if(isRightLarger) l = mid + 1;
            else             r = mid - 1;
            
        }
        return vector<int>{-1, -1};
    }
};
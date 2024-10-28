class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mtx, int target) {
        int m = mtx.size(), n = mtx[0].size();
        int l = 0, r = m * n - 1;
        while(l <= r) {
            int mid = l + (r - l) /2;
            int rw = mid / n, c = mid % n, val = mtx[rw][c];
                 if(val == target) return true;
            else if(val  > target) r = mid - 1;
            else                   l = mid + 1;
        }
        return false;
    }
};
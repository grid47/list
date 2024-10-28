class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& t, int len) {
        
        int n = t.size(), res = 0,
            cover = 0, j = 0, partial = 0;

        sort(t.begin(), t.end());
        
        for(int i = 0; i < n && res < len ; ) {
            if(t[j][0] + len > t[i][1]) {
                cover += t[i][1] - t[i][0] + 1;
                res = max(res, cover);               
                i++;
            } else {
                partial = max(0, t[j][0] + len - t[i][0]);
                res = max(res, cover + partial);
                cover -= (t[j][1] - t[j][0] + 1);
                j++;
            }            
        }
        
        return res;        
    }
};
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& eds, int thd) {
        vector<vector<int>> d(n, vector (n, 10001));
        for(vector<int> &e: eds) {
d[e[0]][e[1]] = d[e[1]][e[0]] = e[2];
}
        for(int i = 0; i < n; i++)
{ d[i][i] = 0; }
        
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
        
        int sm = n +1, res = 0;
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = 0 ; j < n; j++) {
                if(d[i][j] <= thd) {
                    cnt++;
                    }
            }
            
            if (cnt <= sm) {
                res = i;
                sm = cnt;
            }
            
        }
        
        return res;
        
    }
};
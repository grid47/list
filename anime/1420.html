class Solution {
public:

    int mod = (int) 1e9 + 7;

    int numOfArrays(int n, int m, int k) {

        vector<vector<vector<int>>> ways =
            vector<vector<vector<int>>>(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, 0)));

        for(int j = 1; j <= m; j++) ways[1][j][1] = 1;

        for (int ii = 1; ii <= n; ii++)
        for (int ij = 1; ij <= m; ij++)
        for (int ik = 1; ik <= k; ik++) {

            long s = ((long) ij * ways[ii - 1][ij][ik]) % mod;
            for(int l = 1; l < ij; l++) s = (s + ways[ii - 1][l][ik - 1]) % mod;
            ways[ii][ij][ik] = (ways[ii][ij][ik] + s) % mod;

        }

        long res = 0;
        for(int ii = 1; ii <= m; ii++) res = (res + ways[n][ii][k]) % mod;
        
        return (int) res;        
    }
};
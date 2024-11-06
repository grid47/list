class UF {
public:
    vector<int> chd;
    int cnt;
    
    UF(int n) {
        chd.resize(n + 1, 0);
        for(int i = 0; i < n + 1; i++)
            chd[i] = i;
        cnt = n;
    }
    
    bool uni(int x, int y) {
        int i = find(x);
        int j = find(y);
        if(i != j) {
            chd[i] = j;
            cnt--;
            return true;
        } else return false;
    }
    
    int find(int x) {
        if(x == chd[x]) return x;
        return chd[x] = find(chd[x]);
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UF* uf = new UF(n);
        for(int i = 0; i < n; i++)
            if(!uf->uni(edges[i][0], edges[i][1])) {
                return edges[i];
            }
        return edges[0];
    }
};
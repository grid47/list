class Solution {
public:
    vector<string> wds;
    
    bool pre(int i, int j) {
        int p = 0, q = 0;
        if(wds[j].size() < wds[i].size()) return false;
        while(p < wds[i].size() && q < wds[j].size() && wds[i][p] == wds[j][q]) {
            p++; q++;
        }
        return p == wds[i].size();
    }
    
    bool post(int i, int j) {
        int p = wds[i].size() - 1, q = wds[j].size() - 1;
        if(p > q) return false;
        while(p >= 0  && q >= 0 && wds[i][p] == wds[j][q]) {
            p--; q--;
        }
        return p == -1;
    }    
    
    int countPrefixSuffixPairs(vector<string>& w) {
        wds = w;
        int n = w.size(), cnt = 0;
        
        for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(pre(i, j) && post(i, j)) cnt++;
        
        return cnt;
        
    }
};
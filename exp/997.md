
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> deg(n + 1, 0);
        for(auto x: trust) {
            deg[x[1]]++;
            deg[x[0]]--;
        }
        for(int i = 1; i <= n; i++)
            if(deg[i] == n - 1) return i;
        
        return -1;
    }
};
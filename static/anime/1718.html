class Solution {
public:
    int n;
    vector<int> constructDistancedSequence(int n) {
        this-> n = n;
        vector<int> ans(2 * n - 1, 0);
        
        vector<int> vis(n + 1, 0);
        
        bt(ans, vis, 0);
        
        return ans;
        
    }
    
    bool bt(vector<int> &ans, vector<int> &vis, int idx) {
        
        if(idx == ans.size()) return true;
        
        if(ans[idx] != 0) return bt(ans, vis, idx + 1);
        else {

            for(int i = n; i >= 1; i--) {

                if(vis[i]) continue;
                
                vis[i] = 1;
                ans[idx] = i;
                
                if(i == 1) {
                    if(bt(ans, vis, idx + 1)) return true;
                } else if (idx + i < ans.size() && ans[idx + i] == 0) {
                    ans[idx + i] = i;
                    if(bt(ans, vis, idx + 1)) return true;
                    ans[idx + i] = 0;                    
                }
                ans[idx] = 0;
                vis[i] = 0;
                
            }

        }
        return false;
        
    }
    
};
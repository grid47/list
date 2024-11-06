class Solution {
public:
    
    int longestPath(vector<int>& par, string s) {
        int mx = 1;

        int n = s.size();
        vector<int> memo(n, -1), in(n, 0);

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(par[i] != -1) {
                in[par[i]]++;
            }
        }
        for(int i = 0; i < n; i++) {
            if(in[i] == 0) {
                q.push(i);
                memo[i] = 1;
            }
        }
        
        while(!q.empty()) {
            int idx = q.front();
            q.pop();
            if(idx == 0) continue;
            if(s[idx] != s[par[idx]]) {
                if(memo[par[idx]] != -1) {
                    mx = max(mx, memo[par[idx]] + memo[idx]);                    
                }
                if(memo[par[idx]] == -1) {
                    if(memo[idx] == -1) cout << "Yes";
                    memo[par[idx]] = 1 + memo[idx];
                } else if(memo[par[idx]] < 1 + memo[idx]) {
                    memo[par[idx]] = 1 + memo[idx];
                }
                mx = max(mx, memo[par[idx]]);                

            }
                in[par[idx]]--;
                if(in[par[idx]] == 0) {
                    q.push(par[idx]);
                    if(memo[par[idx]] == -1)
                        memo[par[idx]] = 1;
                }

                
        }
        
        return mx;
    }
};
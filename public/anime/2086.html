class Solution {
public:
    vector<int> memo;
    int dp(int idx, string &ham) {
        if(idx >= ham.size()) {
            // cout << ham << "\n";
            return 0;
        }
        if(memo[idx] != -1) return memo[idx];
        
        int ans = 100001;
        if(ham[idx] == 'H') {
            if(idx + 1 < ham.size() && ham[idx + 1] == '.') {
                // ham[idx + 1] = 'C';
                ans = min(ans, 1 + dp(idx + 3, ham));
                // ham[idx + 1] = '.';
            }
            if(idx - 1 >= 0 && (ham[idx - 1] == '.')) {
                // ham[idx - 1] = 'C';
                ans = min(ans, 1 + dp(idx + 1, ham));
                // ham[idx - 1] = '.';                    
            }
        } else {
            ans = dp(idx + 1, ham);
        }
        
        return memo[idx] = ans;
    }
    
    int minimumBuckets(string ham) {
        int n = ham.size();
        memo.resize(n, -1);
        int ans = dp(0, ham);
        return ans >= 100001? -1: ans;
    }
};
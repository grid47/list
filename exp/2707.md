class Solution {
public:
    set<string> dic;
    string str;
    vector<int> memo;
    int n;
    
    int dp(int idx) {
        
        if(idx == n) return 0;
        
        if(memo[idx] != -1) return memo[idx];
        
        int ans = INT_MAX;
        
        int len = 1;
        for(int i = idx; i < n; i++) {
            
            string s = str.substr(idx, len);
            
            if(dic.count(s)) {
                ans = min(ans, dp(idx + len));
            } else {
                ans = min(ans, len + dp(idx + len));                
            }
            
            len++;
        }
        
        return memo[idx] = ans;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        
        n = s.size();
        str = s;
        memo.resize(n, -1);
        
        for(auto x: dictionary) {
            dic.insert(x);
        }
        
        return dp(0);
        
    }
};
class Solution {
public:
    
    int dp(int n) {
        if(n == 0) return 0;
        // cout << n << " " ;
        int ans = 0;
        if((n & 1) == 0) {
            ans = dp(n >> 1);
        } else {
            if(((n >> 1) & 1)== 1) {
            // if(n == 5) cout << "'" << n<< "'";                
                n += 1;
                // while((n & 1) == 0) n >>= 1;
                ans = 1 + dp(n);
            } else {
                ans = 1 + dp(n >> 1);
            }
        }
        return ans;
    }
    
    int minOperations(int n) {
        // aggregate consecutive ones
        // turn of one
        return dp(n);
    }
};
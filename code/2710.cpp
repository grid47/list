class Solution {
public:
    string removeTrailingZeros(string num) {
        int n = num.size();
        int cnt = 0;
        int len;
        for( len = 1; len <= n; len++) {
            if(num[n - len] == '0') cnt++;
            else break;
        }
        return num.substr(0, n - cnt);
    }
};
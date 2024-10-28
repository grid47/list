class Solution {
public:
    vector<vector<int>> mem;
    string s;
    int n;

    int len(int num) {
        return num == 1? 0: num < 10? 1: num < 100? 2: 3;
    }

    int dp(int idx, int k) {

        if(k < 0) return 256;
        if(idx >= n || n - idx <= k) return 0;

        if(mem[idx][k] != -1) return mem[idx][k];

        vector<int> frq(26, 0);
        int ans = 256, most = 0;

        for(int i = idx; i < n; i++) {
            most = max(most, ++frq[s[i]- 'a']);
            ans = min(ans, 1 + len(most) + dp(i + 1, k - (i - idx + 1-most)));
        }

        return mem[idx][k] = ans;
    }

    int getLengthOfOptimalCompression(string s, int k) {
        n = s.length();
        this->s = s;
        mem.resize(n, vector<int>(k + 1, -1));
        return dp(0, k);
    }
};
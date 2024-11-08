class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        string res = "";

        vector<int> in(26, 0), seen(26, 0);
        for (int i = 0; i < n; i++)
            in[s[i] - 'a'] = i;

        vector<int> stk;
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (seen[c]++ > 0) continue;
            while (!stk.empty() && stk.back() > c && i < in[stk.back()]) {
                seen[stk.back()] = 0;
                stk.pop_back();
            }
            stk.push_back(c);
        }

        for (int i = 0; i < stk.size(); i++)
            res += ('a' + stk[i]);

        return res;
    }
};

// that problem was there were
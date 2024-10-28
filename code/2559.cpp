class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& q) {
        int n = words.size();
        vector<int> cnt(n, 0), ans(q.size(), 0);
        set<char> ch = {'a', 'e', 'i', 'o', 'u'};
        for(int i = 0; i < n; i++) {
            if(ch.count(words[i][0]) && ch.count(words[i][words[i].size() -1]))
                cnt[i] = 1;
            if(i > 0) cnt[i] += cnt[i - 1];
        }
        for(int i= 0; i < q.size(); i++) {
            ans[i] = cnt[q[i][1]] - ((q[i][0] > 0)? cnt[q[i][0] - 1]: 0);
        }
        return ans;
    }
};
class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; i++) dp[i].push_back(i);

        int longest_length = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (groups[i] == groups[j]) continue;
                if (words[i].size() != words[j].size()) continue;
                if (getHammingDistance(words[i], words[j]) != 1) continue;

                if ((dp[j].size() + 1) > dp[i].size()) {
                    dp[i] = dp[j];
                    dp[i].push_back(i);
                    longest_length = max(longest_length, int(dp[i].size()));
                }
            }
        }

        vector<string> result;
        for (int i = 0; i < n; i++) {
            if (dp[i].size() == longest_length) {
                for (const int& x : dp[i]) result.push_back(words[x]);
                break;
            }
        }
        return result;
    }
private:
    int getHammingDistance(const string& s, const string& t) {
        int dist = 0;
        int k = s.size();
        for (int i = 0; i < k; i++) {
            if (s[i] != t[i]) dist++;
        }
        return dist;
    }
};
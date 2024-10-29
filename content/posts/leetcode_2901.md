
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2901: Longest Unequal Adjacent Groups Subsequence II"
date = "2016-11-20"
description = "Solution to Leetcode 2901"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii/description/)

---

**Code:**

{{< highlight cpp >}}
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
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


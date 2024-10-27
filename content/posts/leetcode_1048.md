
+++
authors = ["Yasir"]
title = "Leetcode 1048: Longest String Chain"
date = "2021-12-15"
description = "Solution to Leetcode 1048"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-string-chain/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    
    static bool cmp(string &a, string &b) {
        return a.size() < b.size();
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        
        map<string, int> dp;

        int mx = 1;
        
        for(int i = 0; i < words.size(); i++) {
            string w = words[i];
            for(int j = 0; j < w.size(); j++) {
                string w1 = w.substr(0, j) + w.substr(j + 1);
                dp[w] = max(dp[w], dp.count(w1)? dp[w1] + 1: 1);
            }
            mx = max(mx, dp[w]);
        }
        
        return mx;
    }
};
{{< /highlight >}}


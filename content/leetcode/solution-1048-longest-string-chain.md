
+++
authors = ["grid47"]
title = "Leetcode 1048: Longest String Chain"
date = "2024-07-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1048: Longest String Chain in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Two Pointers","String","Dynamic Programming","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "mB13CkhSe3A"
youtube_upload_date="2020-02-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/mB13CkhSe3A/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/longest-string-chain/description/)

---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1048.md" >}}
---
{{< youtube mB13CkhSe3A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1049: Last Stone Weight II](https://grid47.xyz/leetcode/solution-1049-last-stone-weight-ii/) |
| --- |

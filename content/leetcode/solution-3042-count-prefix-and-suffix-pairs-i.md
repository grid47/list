
+++
authors = ["grid47"]
title = "Leetcode 3042: Count Prefix and Suffix Pairs I"
date = "2024-01-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3042: Count Prefix and Suffix Pairs I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Trie","Rolling Hash","String Matching","Hash Function"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "wDPL8oM9rO8"
youtube_upload_date="2024-02-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/wDPL8oM9rO8/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> wds;
    
    bool pre(int i, int j) {
        int p = 0, q = 0;
        if(wds[j].size() < wds[i].size()) return false;
        while(p < wds[i].size() && q < wds[j].size() && wds[i][p] == wds[j][q]) {
            p++; q++;
        }
        return p == wds[i].size();
    }
    
    bool post(int i, int j) {
        int p = wds[i].size() - 1, q = wds[j].size() - 1;
        if(p > q) return false;
        while(p >= 0  && q >= 0 && wds[i][p] == wds[j][q]) {
            p--; q--;
        }
        return p == -1;
    }    
    
    int countPrefixSuffixPairs(vector<string>& w) {
        wds = w;
        int n = w.size(), cnt = 0;
        
        for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(pre(i, j) && post(i, j)) cnt++;
        
        return cnt;
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3042.md" >}}
---
{{< youtube wDPL8oM9rO8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #3043: Find the Length of the Longest Common Prefix](https://grid47.xyz/leetcode/solution-3043-find-the-length-of-the-longest-common-prefix/) |
| --- |

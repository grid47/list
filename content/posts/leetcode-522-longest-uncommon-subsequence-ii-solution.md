
+++
authors = ["grid47"]
title = "Leetcode 522: Longest Uncommon Subsequence II"
date = "2024-09-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 522: Longest Uncommon Subsequence II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Two Pointers","String","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-uncommon-subsequence-ii/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/522.webp" 
    alt="Two strings where the longest uncommon subsequence is searched, and each valid subsequence glows softly."
    caption="Solution to LeetCode 522: Longest Uncommon Subsequence II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        if(strs.empty()) return -1;
        int rst = -1;
        for(auto i = 0; i < strs.size(); i++) {
            int j = 0;
            for(; j < strs.size(); j++) {
                if( i == j ) continue;
                if(LCS(strs[i], strs[j])) break;
            }
            if (j == strs.size())
            rst = max(rst, static_cast<int>(strs[i].size()));
        }
        return rst;
    }
    
    bool LCS(const string& a, const string& b) {
        if(b.size() < a.size()) return false;

        int i = 0;
        for(auto ch : b)
        if (i < a.size() && a[i] == ch) i++;

        return i == a.size();
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/522.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #523: Continuous Subarray Sum](https://grid47.xyz/posts/leetcode-523-continuous-subarray-sum-solution/) |
| --- |

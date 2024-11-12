
+++
authors = ["grid47"]
title = "Leetcode 1358: Number of Substrings Containing All Three Characters"
date = "2024-06-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1358: Number of Substrings Containing All Three Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfSubstrings(string s) {
        return atmost(s, 3) - atmost(s, 2);
    }
    int atmost(string s, int k) {
        map<char, int> ma;
        int res = 0, j = 0;
        for(int i = 0; i < s.size(); i++) {
            ma[s[i]]++;
            if(ma[s[i]] == 1) k--;
            while(k < 0) {
                ma[s[j]]--;
                if(ma[s[j]] == 0) k++;
                j++;
            }
            res += (i - j + 1);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1358.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1361: Validate Binary Tree Nodes](https://grid47.xyz/posts/leetcode-1361-validate-binary-tree-nodes-solution/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 1737: Change Minimum Characters to Satisfy One of Three Conditions"
date = "2024-05-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1737: Change Minimum Characters to Satisfy One of Three Conditions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
    typedef long long ll;
public:
    int minCharacters(string a, string b) {
        int m = a.size(), n = b.size();
        vector<int> ca(26, 0), cb(26, 0);
        for(int i = 0; i < m; i++) {
            ca[a[i] - 'a']++; }
        for(int j = 0; j < n; j++) {
            cb[b[j] - 'a']++; }
        
        int res = m + n;
        for(int i = 0; i < 26; i++) {
            res = min(res, m + n - ca[i] - cb[i]);
            if(i > 0) {

         ca[i] += ca[i - 1];
         cb[i] += cb[i - 1];
                }
            if(i < 25) {
res = min(res, m - ca[i] + cb[i]);
res = min(res, n - cb[i] + ca[i]);

            }
            
            }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1737.md" >}}
---
{{< youtube RRiBv833lVQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1738: Find Kth Largest XOR Coordinate Value](https://grid47.xyz/posts/leetcode-1738-find-kth-largest-xor-coordinate-value-solution/) |
| --- |

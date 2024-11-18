
+++
authors = ["grid47"]
title = "Leetcode 1734: Decode XORed Permutation"
date = "2024-05-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1734: Decode XORed Permutation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "uA9lPzogB7Y"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/decode-xored-permutation/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> decode(vector<int>& enc) {
        int n = enc.size() + 1;
        vector<int> ans(n, 0);
        
        int x = 0;
        for(int i = 1; i < n + 1; i++)
            x ^= i;
        
        ans[0] = x;
        for(int i = 1; i < enc.size(); i += 2)
            ans[0] ^= enc[i];
        
        for(int i = 1; i < n; i++)
            ans[i] = ans[i - 1] ^ enc[i - 1];
        
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1734.md" >}}
---
{{< youtube uA9lPzogB7Y >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1736: Latest Time by Replacing Hidden Digits](https://grid47.xyz/leetcode/solution-1736-latest-time-by-replacing-hidden-digits/) |
| --- |

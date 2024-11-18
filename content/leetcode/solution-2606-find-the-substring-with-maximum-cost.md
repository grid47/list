
+++
authors = ["grid47"]
title = "Leetcode 2606: Find the Substring With Maximum Cost"
date = "2024-02-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2606: Find the Substring With Maximum Cost in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-substring-with-maximum-cost/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        map<char, int> mp;
        for(int i = 0; i < chars.size(); i++) {
            mp[chars[i]] = vals[i];
        }
        for(int i = 0; i < 26; i++) {
            char x = 'a' + i;
            if(mp.count(x)) continue;
            mp[x] = i + 1;
        }
        
        int lmax = 0, gmax = 0;
        for(int i = 0; i < s.size(); i++) {
            if(mp[s[i]] < lmax + mp[s[i]]) {
                lmax = lmax + mp[s[i]];
            } else lmax = mp[s[i]];
            
            gmax = max(gmax, lmax);
        }
        return gmax;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2606.md" >}}
---
{{< youtube EwSIfXGq2B4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2607: Make K-Subarray Sums Equal](https://grid47.xyz/leetcode/solution-2607-make-k-subarray-sums-equal/) |
| --- |

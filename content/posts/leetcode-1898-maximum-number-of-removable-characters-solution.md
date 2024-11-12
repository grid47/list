
+++
authors = ["grid47"]
title = "Leetcode 1898: Maximum Number of Removable Characters"
date = "2024-05-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1898: Maximum Number of Removable Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","String","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-removable-characters/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int isSubseq(string &s, string &p, vector<int>& mp, int k) {
        int i = 0, j = 0;
        while(i < s.size() && j < p.size()) {
            if(mp[i] <= k) {
                i++;
                continue;
            }
            if(s[i] == p[j]) {
                i++;
                j++;
                if(j == p.size()) return true;
            } else i++;
        }
        return false;
    }
    
    int maximumRemovals(string s, string p, vector<int>& rm) {
        vector<int> mp(s.size(), INT_MAX);
        for(int i = 0; i < rm.size(); i++)
            mp[rm[i]] = i;
        int l = 0, r = rm.size() - 1, ans = -1;
        while(l <= r) {
            int mid = l + (r - l + 1) / 2;
            if(isSubseq(s, p, mp, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans + 1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1898.md" >}}
---
{{< youtube NMP3nRPyX5g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1899: Merge Triplets to Form Target Triplet](https://grid47.xyz/posts/leetcode-1899-merge-triplets-to-form-target-triplet-solution/) |
| --- |

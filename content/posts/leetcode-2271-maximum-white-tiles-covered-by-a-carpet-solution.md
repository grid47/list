
+++
authors = ["grid47"]
title = "Leetcode 2271: Maximum White Tiles Covered by a Carpet"
date = "2024-03-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2271: Maximum White Tiles Covered by a Carpet in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Greedy","Sorting","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-white-tiles-covered-by-a-carpet/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& t, int len) {
        
        int n = t.size(), res = 0,
            cover = 0, j = 0, partial = 0;

        sort(t.begin(), t.end());
        
        for(int i = 0; i < n && res < len ; ) {
            if(t[j][0] + len > t[i][1]) {
                cover += t[i][1] - t[i][0] + 1;
                res = max(res, cover);               
                i++;
            } else {
                partial = max(0, t[j][0] + len - t[i][0]);
                res = max(res, cover + partial);
                cover -= (t[j][1] - t[j][0] + 1);
                j++;
            }            
        }
        
        return res;        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2271.md" >}}
---
{{< youtube U7fqZr_ZLd4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #2272: Substring With Largest Variance](https://grid47.xyz/posts/leetcode-2272-substring-with-largest-variance-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

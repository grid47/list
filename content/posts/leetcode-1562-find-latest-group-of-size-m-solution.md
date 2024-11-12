
+++
authors = ["grid47"]
title = "Leetcode 1562: Find Latest Group of Size M"
date = "2024-06-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1562: Find Latest Group of Size M in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-latest-group-of-size-m/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {

        int n = arr.size();
        vector<int> len(n + 2, 0), cnt(n + 1, 0);
        
        int res = -1;
        
        for(int i = 0; i < n; i++) {
            
            int a = arr[i];
            int ll = len[a - 1];
            int rl = len[a + 1];
            len[a] = len[a - ll] = len[a + rl] = ll + rl + 1;
            
            cnt[ll]--;
            cnt[rl]--;
            
            cnt[len[a]]++;
            
            if(cnt[m] > 0) res = i + 1;
            
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1562.md" >}}
---
{{< youtube jUindlyYRuA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1567: Maximum Length of Subarray With Positive Product](https://grid47.xyz/posts/leetcode-1567-maximum-length-of-subarray-with-positive-product-solution/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 1750: Minimum Length of String After Deleting Similar Ends"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1750: Minimum Length of String After Deleting Similar Ends in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumLength(string s) {
        vector<int> pre(3, 0), suf(3, 0);
        
        int i = 0, j = s.size() - 1, len = s.size();
        while(i < j && s[i] == s[j]) {
            char c = s[i];
            while(i < j && s[i] == c) i++;
            while(i < j && s[j] == c) j--;

            len = min(len, j == i? s[i-1]!=s[j]: (j - i + 1));
        }
        return len;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1750.md" >}}
---
{{< youtube 318hrWVr_5U >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1751: Maximum Number of Events That Can Be Attended II](https://grid47.xyz/posts/leetcode-1751-maximum-number-of-events-that-can-be-attended-ii-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

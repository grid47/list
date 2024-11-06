
+++
authors = ["Crafted by Me"]
title = "Leetcode 2914: Minimum Number of Changes to Make Binary String Beautiful"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2914: Minimum Number of Changes to Make Binary String Beautiful in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    // time/space: O(n)/O(1)
    int minChanges(string s) {
        int result = 0;
        int n = s.size();
        for (int i = 0; i < n; i += 2) {
            const char& a = s[i];
            const char& b = s[i + 1];
            if (a != b) result++;
        }        
        return result;
    }
};
{{< /highlight >}}


---
{{< youtube mzozXxrB_fk >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2915: Length of the Longest Subsequence That Sums to Target](https://grid47.xyz/posts/leetcode_2915) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

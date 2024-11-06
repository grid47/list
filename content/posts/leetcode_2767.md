
+++
authors = ["Crafted by Me"]
title = "Leetcode 2767: Partition String Into Minimum Beautiful Substrings"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2767: Partition String Into Minimum Beautiful Substrings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Dynamic Programming","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/partition-string-into-minimum-beautiful-substrings/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
        int minimumBeautifulSubstrings(string s) {
        int n = s.length();
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') continue;
            for (int j = i, cur = 0; j < n; j++) {
                cur = cur * 2 + s[j] - '0';
                if (15625 % cur == 0)
                    dp[j + 1] = min(dp[j + 1], dp[i] + 1);
            }
        }
        return dp[n] > n ? -1 : dp[n];
    }
};
{{< /highlight >}}


---
{{< youtube xV-TA-TtiAg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2768: Number of Black Blocks](https://grid47.xyz/posts/leetcode_2768) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

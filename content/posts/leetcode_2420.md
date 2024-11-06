
+++
authors = ["Crafted by Me"]
title = "Leetcode 2420: Find All Good Indices"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2420: Find All Good Indices in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-all-good-indices/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> goodIndices(vector<int>& a, int k) {
        int n = a.size();
        vector<int> dp1(n + 1, 1), dp2(n + 1, 1), ans;

        for(int i = 1; i < n; i++)
            if(a[i -1] >= a[i]) dp1[i] = dp1[i - 1]+1;
        for(int i = n -2; i > 0; i--)
            if(a[i] <= a[i +1]) dp2[i] = dp2[i +1]+1;

        for(int i = k; i< n-k; i++)
        if(dp1[i-1] >= k && dp2[i+1] >=k)
        ans.push_back(i);

        return ans;
    }
};
{{< /highlight >}}


---
{{< youtube 3JIMkdeoF1c >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2421: Number of Good Paths](https://grid47.xyz/posts/leetcode_2421) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}


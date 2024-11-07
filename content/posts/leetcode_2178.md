
+++
authors = ["Crafted by Me"]
title = "Leetcode 2178: Maximum Split of Positive Even Integers"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2178: Maximum Split of Positive Even Integers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Backtracking","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-split-of-positive-even-integers/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<long long> ans;
    vector<long long> maximumEvenSplit(long long sum) {
        vector<long long> tmp;
        if(sum % 2 == 1) return ans;
        
        int cur = 2;
        while(sum >= cur) {
            ans.push_back(cur);
            sum -= cur;
            cur += 2;
        }
        if(sum > 0) ans[ans.size() - 1] += sum;
        
        return ans;
    }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2178.md" >}}
---
{{< youtube fM7MJFhrm-8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2180: Count Integers With Even Digit Sum](https://grid47.xyz/posts/leetcode_2180) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

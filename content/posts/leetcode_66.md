
+++
authors = ["Crafted by Me"]
title = "Leetcode 66: Plus One"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 66: Plus One in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/plus-one/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        int sum = 1;
        list<int> lst;
        for(int i = d.size() - 1; i >= 0; i--) {
            sum += d[i];
            lst.push_front(sum % 10);
            sum = sum /10;
        }
        if(sum > 0) lst.push_front(sum);
        vector<int> res(lst.begin(), lst.end());
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/66.md" >}}
---
{{< youtube tDjI08W1I7g >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #67: Add Binary](https://grid47.xyz/posts/leetcode_67) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

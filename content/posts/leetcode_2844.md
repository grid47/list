
+++
authors = ["Crafted by Me"]
title = "Leetcode 2844: Minimum Operations to Make a Special Number"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2844: Minimum Operations to Make a Special Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Greedy","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-operations-to-make-a-special-number/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumOperations(string num) {
        bool fivefound = false;
        bool zerofound = false;
        for (int i =num.size()-1; i >=0;i--) {
            
            if (zerofound && num[i]=='0') return num.size()-2-i;
            if (zerofound && num[i]=='5') return num.size()-2-i;
            if (fivefound && num[i]=='2') return num.size()-2-i;
            if (fivefound && num[i]=='7') return num.size()-2-i;
            if (num[i]=='5') fivefound = true;
            if (num[i]=='0') zerofound = true;
            
        }
        if (zerofound) return num.size()-1;
        return num.size();
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2844.md" >}}
---
{{< youtube xFshDEg_Ul4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2845: Count of Interesting Subarrays](https://grid47.xyz/posts/leetcode_2845) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

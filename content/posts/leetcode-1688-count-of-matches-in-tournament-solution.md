
+++
authors = ["grid47"]
title = "Leetcode 1688: Count of Matches in Tournament"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1688: Count of Matches in Tournament in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-of-matches-in-tournament/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfMatches(int n) {
        if(n==0) return 0;
        if(n==1) return 0;
        int ans = n / 2;
        if(n & 1)
        ans += numberOfMatches(n/2 + 1);
        else
        ans += numberOfMatches(n/2);
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1688.md" >}}
---
{{< youtube lslcc0tumpU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1690: Stone Game VII](https://grid47.xyz/posts/leetcode-1690-stone-game-vii-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
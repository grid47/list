
+++
authors = ["Crafted by Me"]
title = "Leetcode 3168: Minimum Number of Chairs in a Waiting Room"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3168: Minimum Number of Chairs in a Waiting Room in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-chairs-in-a-waiting-room/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumChairs(string s) {
        int mx = 0, cnt = 0;
        for(char x: s) {
            cnt += (x == 'E'? 1: -1);
            mx = max(mx, cnt);
        }
        return mx;
    }
};
{{< /highlight >}}


---
{{< youtube -VAEXKFWfXo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #3169: Count Days Without Meetings](https://grid47.xyz/posts/leetcode_3169) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

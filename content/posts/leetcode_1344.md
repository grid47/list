
+++
authors = ["Crafted by Me"]
title = "Leetcode 1344: Angle Between Hands of a Clock"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1344: Angle Between Hands of a Clock in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/angle-between-hands-of-a-clock/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    double angleClock(int h, int minutes) {
        
        double mn = 360 *(double)minutes/60;
        
        double hrs = 360 * ((double)(h == 12? 0: h) / 12) + 30* ((double)minutes/60);
        cout << mn << " " << hrs;
            
        return min(abs(mn - hrs), 360 - (abs(mn - hrs)));
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1344.md" >}}
---
{{< youtube evs3Po8Km7c >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1347: Minimum Number of Steps to Make Two Strings Anagram](https://grid47.xyz/posts/leetcode_1347) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

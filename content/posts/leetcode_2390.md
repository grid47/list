
+++
authors = ["Crafted by Me"]
title = "Leetcode 2390: Removing Stars From a String"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2390: Removing Stars From a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/removing-stars-from-a-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string removeStars(string s) {
        int j = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != '*') s[j++] = s[i];
            else {
                j--;
            }
        }
        return s.substr(0, j);
    }
};
{{< /highlight >}}


---
{{< youtube Qln1aXh2kvQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2391: Minimum Amount of Time to Collect Garbage](https://grid47.xyz/posts/leetcode_2391) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

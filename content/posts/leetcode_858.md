
+++
authors = ["Crafted by Me"]
title = "Leetcode 858: Mirror Reflection"
date = "2022-06-28"
description = "Solution to Leetcode 858"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/mirror-reflection/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mirrorReflection(int p, int q) {
        while( p % 2 == 0 && q % 2 == 0) p >>= 1, q >>= 1;
        return 1 - p%2 + q%2;
    }
};
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/858.md" >}}
- by gpt
        
---
{{< youtube fUa0LRtSlz0 >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


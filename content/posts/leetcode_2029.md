
+++
authors = ["Crafted by Me"]
title = "Leetcode 2029: Stone Game IX"
date = "2018-04-13"
description = "Solution to Leetcode 2029"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/stone-game-ix/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> m(3, 0);
        for(int a: stones)
        m[a % 3]++;
        if(min(m[2], m[1]) == 0)
        return max(m[1], m[2]) > 2 && m[0] % 2 >0;
        return abs(m[1] - m[2]) > 2 || m[0] % 2 == 0;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


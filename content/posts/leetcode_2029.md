
+++
authors = ["Yasir"]
title = "Leetcode 2029: Stone Game IX"
date = "2019-04-09"
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

{{< highlight html >}}
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


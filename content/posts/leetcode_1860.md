
+++
authors = ["Yasir"]
title = "Leetcode 1860: Incremental Memory Leak"
date = "2019-09-25"
description = "Solution to Leetcode 1860"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/incremental-memory-leak/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> memLeak(int mem1, int mem2) {
        int i = 1;
        while(i <= mem1 || i <= mem2) {
            if(mem1 >= mem2) {
                mem1 -= i;
            } else mem2 -= i;
            i++;
        }
        return vector<int>{i, mem1, mem2};
    }
};
{{< /highlight >}}



+++
authors = ["grid47"]
title = "Leetcode 2183: Count Array Pairs Divisible by K"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2183: Count Array Pairs Divisible by K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Number Theory"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-array-pairs-divisible-by-k/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
    public long countPairs(int[] nums, int k) {
        long res = 0;
        HashMap<Integer, Integer> gm = new HashMap<>();
        for(int num: nums) {

            int gcd = findGCD(num, k);

            for(int node: gm.keySet()) {

                if((long) gcd * node % k == 0) 
                    res += gm.get(node);

            }

            gm.put(gcd, gm.getOrDefault(gcd, 0) + 1);
        }

        return res;
    }
    
    private int findGCD(int x, int y) {

        if (x < y) return findGCD(y, x);

        return y == 0 ? x : findGCD(y, x % y);

    }
}
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2183.md" >}}
---
{{< youtube 1K6O9KtKs1k >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2185: Counting Words With a Given Prefix](https://grid47.xyz/posts/leetcode-2185-counting-words-with-a-given-prefix-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

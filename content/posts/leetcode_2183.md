
+++
authors = ["Crafted by Me"]
title = "Leetcode 2183: Count Array Pairs Divisible by K"
date = "2018-11-11"
description = "In-depth solution and explanation for Leetcode 2183: Count Array Pairs Divisible by K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2184: Number of Ways to Build Sturdy Brick Wall](https://grid47.xyz/posts/leetcode_2184) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


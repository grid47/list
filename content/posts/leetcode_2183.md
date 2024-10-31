
+++
authors = ["Crafted by Me"]
title = "Leetcode 2183: Count Array Pairs Divisible by K"
date = "2018-11-10"
description = "Solution to Leetcode 2183"
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


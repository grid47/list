
+++
authors = ["Crafted by Me"]
title = "Leetcode 357: Count Numbers with Unique Digits"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 357: Count Numbers with Unique Digits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Dynamic Programming","Math","Backtracking","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-numbers-with-unique-digits/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
    public int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        
        int res = 10;
        int available = 9;
        int unqNums = 9;
        
        while(n-- > 1 && available > 0) {
            unqNums = unqNums * available;
            res += unqNums;
            available--;
        }
        return res;
    }
}
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/357.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #358: Rearrange String k Distance Apart](https://grid47.xyz/posts/leetcode_358) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}



+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 357: Count Numbers with Unique Digits"
date = "2023-11-08"
description = "Solution to Leetcode 357"
tags = [
    
]
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


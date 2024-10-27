
+++
authors = ["Yasir"]
title = "Leetcode 357: Count Numbers with Unique Digits"
date = "2023-11-06"
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

{{< highlight html >}}
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


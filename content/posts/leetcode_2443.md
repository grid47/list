
+++
authors = ["Yasir"]
title = "Leetcode 2443: Sum of Number and Its Reverse"
date = "2018-02-19"
description = "Solution to Leetcode 2443"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-number-and-its-reverse/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int rev(int num) {
        int tmp = 0;
        while(num) {
            tmp = tmp * 10 + num % 10;
            num /= 10;
        }
        return tmp;
    }
    
    bool sumOfNumberAndReverse(int num) {
        
        for(int i = 0; i <= num; i++) {
            if((i + rev(i) )== num) {
                return true;
            }
        }
        return false;
    }
};
{{< /highlight >}}


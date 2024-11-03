
+++
authors = ["Crafted by Me"]
title = "Leetcode 2443: Sum of Number and Its Reverse"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2443: Sum of Number and Its Reverse in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-number-and-its-reverse/description/)

---

**Code:**

{{< highlight cpp >}}
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


---
{{< youtube ESqVFCHtAGg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2444: Count Subarrays With Fixed Bounds](https://grid47.xyz/posts/leetcode_2444) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


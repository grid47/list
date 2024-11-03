
+++
authors = ["Crafted by Me"]
title = "Leetcode 2507: Smallest Value After Replacing With Sum of Prime Factors"
date = "2017-12-22"
description = "In-depth solution and explanation for Leetcode 2507: Smallest Value After Replacing With Sum of Prime Factors in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int getFactSum(int n) {
        int div = 2, sum = 0;
        while(n > 1) {
            if(n % div == 0) {
                sum += div;
                n /= div;
            } else div++;
        }
        return sum;
    }
    
    int smallestValue(int n) {
        
        while(1) {
            int sum = getFactSum(n);
            if(sum == n) break;
            n = sum;
        }
        return n;
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2508: Add Edges to Make Degrees of All Nodes Even](https://grid47.xyz/posts/leetcode_2508) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}



+++
authors = ["Crafted by Me"]
title = "Leetcode 2928: Distribute Candies Among Children I"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2928: Distribute Candies Among Children I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/distribute-candies-among-children-i/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int distributeCandies(int n, int limit) {
        int res = 0;
        for(int i = 0; i <= limit; ++i){
            for(int j = 0; j <= limit; ++j){
                for(int k = 0; k <= limit; ++k){
                    if(i + j + k == n) { res++; }
                }
            }
        }
        return res;
    }
};
{{< /highlight >}}


---
{{< youtube hVNcZKh8r40 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2929: Distribute Candies Among Children II](https://grid47.xyz/posts/leetcode_2929) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}



+++
authors = ["Crafted by Me"]
title = "Leetcode 2678: Number of Senior Citizens"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2678: Number of Senior Citizens in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-senior-citizens/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(auto i : details) {
            if(i[11] - '0' > 6) count++;
            else if (i[11] - '0' == 6 && i[12] - '0' > 0) count++;
        }
        return count;
    }
};
{{< /highlight >}}


---
{{< youtube l6_wwKzFmVo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2679: Sum in a Matrix](https://grid47.xyz/posts/leetcode_2679) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


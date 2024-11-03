
+++
authors = ["Crafted by Me"]
title = "Leetcode 2027: Minimum Moves to Convert String"
date = "2019-04-16"
description = "In-depth solution and explanation for Leetcode 2027: Minimum Moves to Convert String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-moves-to-convert-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumMoves(string s) {
        int i = 0, n = s.length(), count = 0;
        while (i < n) {
            if (s[i] == 'O')
                i++;
            else
                count++, i += 3;
        }
        return count;
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2028: Find Missing Observations](https://grid47.xyz/posts/leetcode_2028) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

